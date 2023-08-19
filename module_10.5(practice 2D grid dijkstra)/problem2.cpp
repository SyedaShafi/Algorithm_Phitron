#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int INF = INT_MAX;
const int N = 1e5 + 1;
typedef pair<int, int> pii;
vector<pair<int, int>> graph[N];
bool vis[N];
vector<int> dist(N, INF);
void dijkstra(int node)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[node] = 0;
    pq.push({dist[node], node});
    while (!pq.empty())
    {
        int par = pq.top().second;
        pq.pop();
        vis[par] = true;
        for (auto child : graph[par])
        {
            int n, w;
            n = child.first;
            w = child.second;
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
    }

    int s, d;
    cin >> s >> d;
    dijkstra(s);
    cout << dist[d] << "\n";
}