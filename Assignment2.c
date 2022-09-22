// Muhammad Ibrahim Siddiqui, Algorithms Assignment 2
// Implementing BinarySearch with Dynamic Programming for weighted Intervals.
// Code to execute:-  gcc Assignment2.c
// ./a.out <input.txt


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[100][100] = {};
int B[100] = {};
int start[100] = {};
int finish [100] = {};
int weight[100] = {};

struct node 
{
  int value;
  struct node *next;
};

int MaxNum(int i ,int j )
{
if (i>j)
  return i;
  return j;
}

int BinSearch(int *input,int n,int Searchkey)
{
// This function takes an input of an array, with n number of index. Plus the value to be searched.
// It either returrs the index value if found or -1.
  int i,j,k;
   i=0;
   j=n-1;
  while (i<=j)
  {
    k=(i+j)/2;
    if (input[k]<= Searchkey)
    {
      i=k+1;
    }
    else
    {
      j=k-1;
    }
  }
  return j;
}



int main(int argc, char *argv[])
{
  int n;
  scanf("%d\n",&n);


  for ( int i = 0 ; i < n ; i++)
  {
    scanf("%d %d %d" ,&start[i],&finish[i],&weight[i]);
  }

  for (int i = 0 ; i < n ; i ++)
  {
    printf("%d %d %d\n",start[i],finish[i],weight[i]);
  }

  int i = 0;
  finish[0]=(-9999); 
  for (i=1;i<=n;i++)
    B[i]=BinSearch(finish,n+1,start[i]);

  A[0][0]=0;
  for (i=1;i<=n;i++)
  A[i][0]= A[0][i] = MaxNum(weight[i]+A[B[i]][0],A[i-1][0]);

  for (int i = 1 ; i <= n ; i++)
  for (int j = 1 ; j <=n ; j++)
  {

    if (i<j)
    {
      A[i][j] =  MaxNum(A[i][B[j]]+weight[j],A[i][j-1]);
    }

    if (i == j)
    {
        A[i][j] =   A[i][j-1];
    }

    if  (i > j)
    {
      A[i][j] = MaxNum(A[B[i]][j]+weight[i],A[i-1][j]);
    }
  }
  printf("  i   s   f   v   p  \n");
  for (i=1;i<=n;i++)
  printf("%3d %3d %3d %3d %3d \n",i,start[i],finish[i],weight[i],B[i]);
  int j = 0;
  printf(" A\n");
  for (i=1;i<=n;i++)
  {
     for ( j = 0 ; j <= n ; j++)
     {
        printf("%3d%3d",i , j );
        printf(" %3d\n",A[i][j]);
     }
  }
  
  j  = n; 
  i =n;
  int sum = 0;
  while (i!= 0 || j!=0 )
  // Conditions being set for the assignment of values to Room 1
  if (i>j)
  {
    if (weight[i]+A[B[i]][j]>=A[i-1][j])
    {
      printf("Room 1  gets %d\n", i);
      sum =sum +weight[i];
      i = B[i];
    }
    else 
    {
      i--;
    }
  }

  else if (i == j)
  {
    i--;
  }
  else if (i<j)
  {
  if (weight[j]+A[i][B[j]]>=A[i][j-1])
    {
       // Conditions being set for the assignment of values to Room 2
      printf("Room 2  gets %d\n", j);
      sum =sum +weight[j];
      j = B[j]; 
    }
  else 
  {
    j--;
  }

  printf("%d %d", sum , A[n][n]);
  }
  
  printf("sum is %d\n",sum);

}

