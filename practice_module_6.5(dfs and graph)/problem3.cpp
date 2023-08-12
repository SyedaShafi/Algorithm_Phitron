#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 1;
vector<int> adj_list[N];
int matrix[N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int child : adj_list[i])
        {
            matrix[i][child] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}