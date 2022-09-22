// Muhammad Ibrahim Siddiqui
// 1001753339,, This is Subset_Sum (Assignment 3)

// ssh mxs3339@omega.uta.edu
// compilation: gcc subset_sum.c 
// run: ./a.out < a.txt

// time complexity: O(m*n) where m = array size, n = sum/3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Arr1, stores the numbers that we use. 
// index is the value used as a counter to go over the array of numbers. 
// a is the numebr used to calculate the sun. 
// flag, tells us if we've already visited a certain index number.
 
int solve(int* Arr1, int index, int a, int **flag2, int sum, int* flag)
{
    if(sum == 0)
    {
        return 1;
    }
    if(index == a || sum < 0)
    {
        return 0;
    }
    if(flag2[index][sum] != -1) 
    return flag2[index][sum];
    flag2[index][sum] = solve(Arr1, index + 1, a, flag2, sum, flag);
    if(flag[index] == -1)
    {
        flag2[index][sum] = flag2[index][sum] | solve(Arr1, index + 1, a, flag2, sum - Arr1[index], flag);
    }
    return flag2[index][sum];
}



void markSubsequece(int* Arr1, int index, int a, int** flag2, int sum, int* flag, int id)
{
    if(sum == 0) 
    {
        return;
    }
    if(solve(Arr1, index + 1, a, flag2, sum, flag))
    {
        markSubsequece(Arr1, index + 1, a, flag2, sum, flag, id);
    } 
    else 
    {
        flag[index] = id;
        markSubsequece(Arr1, index + 1, a, flag2, sum - Arr1[index], flag, id);
    }
}

int main()
{

    int a,i,j;
    int TotalSum = 0;

    scanf("%d", &a);
    printf("Number of elements: %d\n", a);
    int *Arr1 = (int*)malloc(a * sizeof(int));
   
    for(i = 0; i < a; i++)
    {
        scanf("%d", &Arr1[i]);
        TotalSum += Arr1[i];
    }
    printf("Elements:");
    for( i = 0; i < a; i++)
    {
        printf(" %d", Arr1[i]);
    }
    printf("\n");
    if(TotalSum % 3 != 0)
    {
        printf("No partition is possible\n");
    } 
    else 
    {
        int Half = TotalSum/3;
        int *flag = (int*)malloc(a * sizeof(int));
        int** flag2 = (int**)malloc(a * sizeof(int*));
        for(i = 0; i < a; i++)
        {
            flag[i] = -1;

            flag2[i] = (int*)malloc((Half+1) * sizeof(int));

            for(j = 0; j <= Half; j++)
            {
                flag2[i][j] = -1;
            }
        }
        if(solve(Arr1, 0, a, flag2, Half, flag))
        {
            markSubsequece(Arr1, 0, a, flag2, Half, flag, 0);
            for(i = 0; i < a; i++)
            {
                for(j = 0; j <= Half; j++)
                {
                    flag2[i][j] = -1;
                }
            }
            if(solve(Arr1, 0, a, flag2, Half, flag))
            {
                markSubsequece(Arr1, 0, a, flag2, Half, flag, 1);
                printf("%3s%5d%5d%5d\n", "i", 0, 1, 2);
                for( i = 0; i < a; i++)
                {
                    printf("%3d", i+1);
                    if(flag[i] == 0) printf("%5d\n", Arr1[i]);
                    else if(flag[i] == 1) printf("%10d\n", Arr1[i]);
                    else printf("%15d\n", Arr1[i]);
                }
                printf("\n");
            } 
            else 
            {
                printf("No partition is possible\n");
            }
        }
        else
        {
            printf("No partition is possible\n");
        }
    }
    
    return 0;
}
