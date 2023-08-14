#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
const int INF = INT_MAX;
vector<pair<int, int>> graph[N];
bool vis[N];
vector<int> dist(N, INF);
void dijkstra(int node)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[node] = 0;
    pq.push({dist[node], node});
    while (!pq.empty())
    {
        int parent = pq.top().second;
        pq.pop();
        vis[parent] = true;
        for (pair<int, int> vp : graph[parent])
        {
            int w = vp.second;
            int v = vp.first;
            if (vis[v])
                continue;
            if (dist[v] > dist[parent] + w)
            {
                dist[v] = dist[parent] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "distance of node " << i << " : ";
        cout << dist[i] << "\n";
    }
}