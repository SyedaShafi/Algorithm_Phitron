#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> adj[N];
bool vis[N];
void dfs(int u)
{
    vis[u] = true;
    cout << "visiting node: " << u << "\n";
    for (int ele : adj[u])
    {
        if (!vis[ele])
            dfs(ele);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
}