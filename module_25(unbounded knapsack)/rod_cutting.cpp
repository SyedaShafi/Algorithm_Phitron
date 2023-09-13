#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
int dp[1000][1000];

int unbounded_knapsack(int n, int w, int val[], int weight[])
{
    if (n == 0 || w == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (weight[n - 1] <= w)
    {
        int op1 = val[n - 1] + unbounded_knapsack(n, w - weight[n - 1], val, weight);
        int op2 = unbounded_knapsack(n - 1, w, val, weight);
        return dp[n][w] = max(op1, op2);
    }
    else
    {
        return dp[n][w] = unbounded_knapsack(n - 1, w, val, weight);
    }
}

int main()
{
    int n;
    cin >> n;
    int val[n], w[n];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        w[i] = i + 1;
    }
    cout << unbounded_knapsack(n, n, val, w);
}