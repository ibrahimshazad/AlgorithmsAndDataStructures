//This is algoirthm Assignment 4, Red-Black Tree coding.
// Muhammad Ibrahim Siddiqui, 1001753339
// Compilation command on omega, ssh mxs3339@omega.uta.edu
// gcc Assignment4.c 
// ./a.out

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum _Color
{
    Black,
    Red
}Color;

typedef struct _RBNode 
{
    Color color;
    int blackHeight;
}RBNode;

int countNodes(char* data)
{
    size_t length = strlen(data);
    size_t i;
    int count = 0;
    

    for(i = 0; i < length; i++)
    {
        if(data[i] == '.')
        {
            count++;
        }
    }
    return count-1;
}

int isNode(char c)
{
    return (c == 'B' || c == 'R');
}



int main()
{
    char data[1024];

    // Scanning the input and printing the data
    scanf("%s", data);
    printf("%s\n", data);

    int CountNode = countNodes(data);
    RBNode stack[CountNode];

    int TempCount,LastId = 0;
    int ValidBit = 1;

    size_t length = strlen(data);
    size_t i = 2;
    size_t j;

    
    while(i < length)
    {
        if(isNode(data[i]))
        {
            RBNode parent;
            parent.color = (data[i] == 'B')?Black:Red;
            parent.blackHeight = (parent.color == Black);
            if(TempCount > 0)
            {
                TempCount--;
            }
            if(isNode(data[i-1]))
            {
                RBNode right = stack[LastId-1];
                LastId--;
                if(TempCount == 0 && LastId > 0)
                {
                    RBNode left = stack[LastId-1];
                    LastId--;
                    if(parent.color == Red)
                    {
                        if(left.color == Red || right.color == Red)
                        {
                            ValidBit = 0;
                            for( j = 0; j < i; j++)
                            {
                                printf(" ");
                            }
                            printf("^ Consecutive red node error\n");
                            break;
                        }
                    }
                    if(left.blackHeight != right.blackHeight)
                    {
                        ValidBit = 0;
                        for(j = 0; j < i; j++)
                        {
                            printf(" ");
                        }
                        printf("^ Black height error\n");
                        break;
                    }
                    parent.blackHeight += (right.blackHeight > left.blackHeight)?right.blackHeight:left.blackHeight;
                }
                else 
                {
                    if(parent.color == Red && right.color == Red)
                    {
                            ValidBit = 0;
                            for(j = 0; j < i; j++)
                            {
                                printf(" ");
                            }
                            printf("^ Consecutive red node error\n");
                            break;
                    }
                    parent.blackHeight += right.blackHeight;
                }
            } 
            else if(isNode(data[i-2]))
            {
                RBNode left = stack[LastId-1];
                LastId--;
                if(parent.color == Red && left.color == Red)
                {
                        ValidBit = 0;
                        for(j = 0; j < i; j++)
                        {
                            printf(" ");
                        }
                        printf("^ Consecutive red node error\n");
                        break;
                }
                parent.blackHeight += left.blackHeight;
            }
            stack[LastId++] = parent;
        } 
        else if(data[i] !='.')
        {
            ValidBit = 0;
            for(j = 0; j < i; j++)
            {
                printf(" ");
            }
            printf("^ Bad character\n");
            break;
        } 
        else 
        {
            if(isNode(data[i-1]))
            {
                TempCount = 0;
            }
            TempCount++;
        }
        i++;
    }
    if(ValidBit)
    {
        if(LastId == 1)
        {
            printf("Input is a legal RB tree\n");
        } 
        else 
        {
            for(j = 0; j < i; j++)
            {
                printf(" ");
            }
            printf("^ Input string does not represent a tree\n");
        }
    }
    return 0;
}
