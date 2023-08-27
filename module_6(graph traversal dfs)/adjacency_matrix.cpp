#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 1;
int adj_matrix[N][N];
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}