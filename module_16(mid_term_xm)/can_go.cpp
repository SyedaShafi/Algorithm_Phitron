#include <bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
vector<pii> graph[N];
bool vis[N];
vector<int> dist(N, INF);
void dijkstra(int node)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[node] = 0;
    pq.push({dist[node], node});
    while (!pq.empty())
    {
        pii par = pq.top();
        pq.pop();
        int u, w;
        u = par.second, w = par.first;
        vis[u] = true;
        for (auto ele : graph[u])
        {
            int nn = ele.first;
            int nw = ele.second;
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
    }
    int src;
    cin >> src;
    dijkstra(src);
    int t;
    cin >> t;
    while (t--)
    {
        int d, cost;
        cin >> d >> cost;
        // cout << dist[d] << " " << cost << "\n";
        if (dist[d] <= cost and vis[d] == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}