#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> graph[N];
bool vis[N];

void dfs(int node)
{
    vis[node] = true;
    for (int child : graph[node])
    {
        if (!vis[child])
            dfs(child);
    }
}

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : graph[parent])
        {
            if (vis[child])
                continue;
            q.push(child);
            vis[child] = true;
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
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
            cnt++;
        }
    }
    cout << "Number of connected component :" << cnt << "\n";
}