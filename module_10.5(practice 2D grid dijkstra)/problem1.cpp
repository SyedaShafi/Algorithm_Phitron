#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
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
        int par = pq.top().second;
        pq.pop();
        vis[par] = true;
        for (auto pr : graph[par])
        {
            int n = pr.first;
            int w = pr.second;
            if (vis[n])
                continue;
            if (dist[n] > dist[par] + w)
            {
                dist[n] = dist[par] + w;
                pq.push({dist[n], n});
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
    int s, d;
    cin >> s >> d;
    dijkstra(s);
    cout << dist[d];
}