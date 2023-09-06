#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 1;
const int INF = 1e9 + 1;
typedef pair<int, int> pii;
vector<pii> graph[N];
bool vis[N];
vector<int> dist(N, INF);
void dijkstra(int node)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, node});
    dist[node] = 0;
    while (!pq.empty())
    {
        pii pr = pq.top();
        pq.pop();
        int u, w;
        w = pr.first;
        u = pr.second;
        vis[u] = true;
        for (auto ele : graph[u])
        {
            int nn, nw;
            nn = ele.first;
            nw = ele.second;
            if (vis[nn])
                continue;
            if (dist[nn] > dist[u] + nw)
            {
                dist[nn] = dist[u] + nw;
                pq.push({dist[nn], nn});
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
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
        cout << dist[i] << "\n";
}