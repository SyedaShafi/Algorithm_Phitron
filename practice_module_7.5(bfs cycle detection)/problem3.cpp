#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> graph[N];
int vis[N];

bool dfs(int node, int parent)
{
    bool cycle = false;
    vis[node] = true;
    for (int child : graph[node])
    {
        if (child == parent)
            continue;
        if (vis[child])
            return true;
        cycle |= dfs(child, node);
    }
    return cycle;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool f = dfs(1, -1);
    if (f)
        cout << "YES\n";
    else
        cout << "NO\n";
}