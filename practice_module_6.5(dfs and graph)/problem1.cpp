#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> graph[N];
bool vis[N];
vector<int> v;
void dfs(int node)
{
    vis[node] = true;
    v.push_back(node);
    for (int child : graph[node])
    {
        if (vis[child])
            continue;
        dfs(child);
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
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);
    for (int i = n - 1; i >= 0; i--)
        cout << v[i] << " ";
}