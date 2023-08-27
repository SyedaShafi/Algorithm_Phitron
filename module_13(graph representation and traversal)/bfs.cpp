#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 1;
vector<int> graph[N];
bool vis[N];
int dist[N];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int ele : graph[p])
        {
            if (!vis[ele])
            {
                q.push(ele);
                dist[ele] = dist[p] + 1;
                vis[ele] = true;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << "\n";
    }
}