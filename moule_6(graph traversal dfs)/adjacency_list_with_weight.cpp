#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<pair<int, int>> adj[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Node: " << i << " = ";
        for (auto ele : adj[i])
        {
            cout << "(" << ele.first << " " << ele.second << ") ";
        }
        cout << "\n";
    }
}