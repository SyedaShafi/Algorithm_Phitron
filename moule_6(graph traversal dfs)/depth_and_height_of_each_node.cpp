#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> adj[N];
bool vis[N];
int depth[N];
int height[N];

void dfs(int u)
{
    vis[u] = true;
    // cout << "visiting node: " << u << "\n";
    for (int ele : adj[u])
    {
        if (!vis[ele])
        {
            depth[ele] = depth[u] + 1;
            dfs(ele);
            height[u] = max(height[ele] + 1, height[u]);
        }
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
    for (int i = 1; i <= n; i++)
    {
        cout << "depth of node : " << i << " : " << depth[i];
        cout << "\n";
    }
    cout << "\n\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "height of node : " << i << " : " << height[i];
        cout << "\n";
    }
}