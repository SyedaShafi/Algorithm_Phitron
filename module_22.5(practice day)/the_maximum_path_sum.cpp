#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 15;
int g[15][15];
int path_sum(int n, int m, int i, int j)
{
    if (i == n and j == m)
        return g[i][j];
    if (i > n || j > m)
        return INT_MIN;
    int s1 = path_sum(n, m, i + 1, j);
    int s2 = path_sum(n, m, i, j + 1);
    return g[i][j] + max(s1, s2);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }

    cout << path_sum(n, m, 1, 1);
}