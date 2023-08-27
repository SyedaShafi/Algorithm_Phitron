#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 1;
const int INF = 1e9 + 1;
int d[N][N];
int n, m;
void dist_initialize()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                d[i][j] = INF;
        }
    }
}
void print_matrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == INF)
                cout << "x ";
            else
                cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    cin >> n >> m;
    dist_initialize();
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        // d[v][u] = w;//undirected graph
    }
    print_matrix();

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    cout << "\n";
    print_matrix();
}