/*
Rohan Bankala
1001734897
Compilation command used on: gcc lab3_rkb4897.c
./a.out < input.txt
Worst-case time: O(n*m) */
#include <stdio.h> #include <stdlib.h> #include <string.h>
int ans(int* in_array, int curr_index, int n, int **dp, int sum, int* vis)
{
if(sum == 0)
{
return 1;
}
if(curr_index == n || sum < 0)
{
return 0;
}
if(dp[curr_index][sum] != -1) return dp[curr_index][sum]; dp[curr_index][sum] = ans(in_array, curr_index + 1, n, dp, sum, vis); if(vis[curr_index] == -1)
{
dp[curr_index][sum] = dp[curr_index][sum] | ans(in_array, curr_index + 1, n, dp, sum - in_array[curr_index], vis);
}
return dp[curr_index][sum]; }
void marking(int* in_array, int curr_index, int n, int** dp, int sum, int* vis, int
id){
if(sum == 0) return;
if(ans(in_array, curr_index + 1, n, dp, sum, vis)) {
marking(in_array, curr_index + 1, n, dp, sum, vis, id); }
else {
vis[curr_index] = id;
marking(in_array, curr_index + 1, n, dp, sum - in_array[curr_index], vis,
} }
int main() {
    int n;
    int i;
    int j;
    scanf("%d", &n);
id);

int *in_array = (int*)malloc(n int sum = 0;
for(i = 0; i < n; i++)
{
scanf("%d", &in_array[i]);
sum += in_array[i]; }
printf("\n");
if(sum % 3 != 0)
{
    printf("No solution\n");
}
else {
* sizeof(int));
int part = sum/3;
printf("%d/3 = %d\n", sum, part); printf(" i S\n"); printf("-------\n");
for(i = -1; i < n; i++)
{
printf("%3d %3d\n", i+1, in_array[i]); }
printf("------------------\n");
int *vis = (int*)malloc(n * sizeof(int));
int** dp = (int**)malloc(n * sizeof(int*));
for(i = 0; i < n; i++)
{
vis[i] = -1;
dp[i] = (int*)malloc((part+1) * sizeof(int)); for(j = 0; j <= part; j++)
{
dp[i][j] = -1; }
}
if(ans(in_array, 0, n, dp, part, vis))
{
marking(in_array, 0, n, dp, part, vis, 0); for(i = 0; i < n; i++)
{
        for(j = 0; j <= part; j++)
        {
dp[i][j] = -1; }
}
if(ans(in_array, 0, n, dp, part, vis))
{
marking(in_array, 0, n, dp, part, vis, 1); printf("%3s%5d%5d%5d\n", "i", 0, 1, 2); for(i = 0; i < n; i++)
{
printf("%3d", i+1);
if(vis[i] == 0) printf("%5d\n", in_array[i]);
else if(vis[i] == 1) printf("%10d\n", in_array[i]); else printf("%15d\n", in_array[i]);

}
                printf("\n");
            }
else {
                printf("No solution\n");
            }
}
else {
            printf("No solution\n");
        }
}
return 0; }
