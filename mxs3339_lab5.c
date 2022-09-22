// This is coding assignment 5, Muhammad Ibrahim Siddiqui, 1001753339
//Compilation command used on OMEGA
//gcc mxs3339_lab5.c
//./a.out < "input file used"

#include <stdio.h>

#define MAX 999999999

int Var1;

int MinimumValue(int i, int j)
{
    return (i<j)?i:j;
}

void PrintMatrix(int Final[][Var1],int Minimum[][Var1])
{
    int i, j;
    for(i = 0; i < Var1; i++)
    {
        for(j = 0; j < Var1; j++)
        {
            if(Final[i][j] == MAX)
            {
                printf("%-6c",236);
            }
            else
            {
                printf("%-2d %-2d ",Minimum[i][j],Final[i][j]);
            }
        }
        printf("\n");
    }
    printf("------------------------------\n");
}

void PathPrint(int Final[][Var1], int i, int j)
{
    if(Final[i][j] == j)
    {
        printf(" %d", j);
        return;
    }
    printf(" %d",Final[i][j]);
    PathPrint(Final, Final[i][j],j);
}

void GraphPrint(int Final[][Var1], int top)
{
    int j;
    printf("Vertex %d is a leader\n", top);
    for(j = 0; j < Var1; j++)
    {
        if(top != j &&  Final[top][j] != MAX && Final[j][top] != MAX)
        {
            printf("Vertex path to leader is: %d", j);
            PathPrint(Final, j, top);
            printf("\n\n");
            printf("Vertex path from leader is: %d", top);
            PathPrint(Final, top, j);
            printf("\n\n");
        }
    }
}

void WarshalTechnique(int graph[][Var1])
{
    int Distance[Var1][Var1];
    int Final[Var1][Var1];
    int Minimum[Var1][Var1];
    int i,j,k;

    for(i =0 ; i < Var1; i++)
    {
        for(j = 0; j < Var1 ; j++)
        {
            Distance[i][j] = graph[i][j];
            Minimum[i][j] = (i<j)?i:j;
            if(Distance[i][j] != MAX)
            {
                Final[i][j] = j;
            }
            else
            {
                Final[i][j] = MAX;
            }
        }
    }
    PrintMatrix(Final, Minimum);
    for(k = 0; k < Var1; k++)
    {
        for(i = 0; i < Var1; i++)
        {
            for(j = 0; j < Var1; j++)
            {
                if(Distance[i][k] + Distance[k][j] < Distance[i][j])
                {
                    Distance[i][j] = Distance[i][k] + Distance[k][j];
                    Final[i][j] = Final[i][k];
                    Minimum[i][j] = MinimumValue(MinimumValue(Minimum[i][j], Minimum[i][k]), Minimum[k][j]);
                } else if(Distance[i][k] + Distance[k][j] < MAX){
                    Minimum[i][j] = MinimumValue(MinimumValue(Minimum[i][j], Minimum[i][k]), Minimum[k][j]);
                }
            }
        }

        for(i = 0; i < Var1; i++)
        {
            for(j = 0; j < Var1; j++)
            {
                if(Distance[i][k] + Distance[k][j] < MAX)
                {
                    Minimum[i][j] = MinimumValue(MinimumValue(Minimum[i][j], Minimum[i][k]), MinimumValue(Minimum[k][j], Minimum[i][j]));
                }
            }
        }
        PrintMatrix(Final, Minimum);
    }
    int Leader[Var1];
    for(i  = 0; i < Var1; i++){
        Leader[i] = 1;
    }
    for(i = 0; i < Var1; i++){
        if(Leader[i] == 1){
            for(j = i + 1; j < Var1; j++){
                if(Final[i][j] != MAX && Final[j][i] != MAX)
                {
                    Leader[j] = 0;
                }
            }
            GraphPrint(Final, i);
        }
    }
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int Origin,FinalDestination;
    Var1 = n;
    int graph[n][n];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j){
                graph[i][j] = 0;
            }
            else{
                graph[i][j] = MAX;
            }
        }
    }
    while(1)
    {
        if(Origin == -1 && FinalDestination == -1)
        {
            break;
        }
        scanf("%d%d",&Origin,&FinalDestination);
        graph[Origin][FinalDestination] = 1;
    }
    WarshalTechnique(graph);
}
