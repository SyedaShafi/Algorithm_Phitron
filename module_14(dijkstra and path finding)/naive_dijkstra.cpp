// complexity O(N*E)
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int INF = INT_MAX;
const int N = 1e3 + 1;
typedef pair<int, int> pii;
vector<pii> graph[N];
vector<int> dist(N, INF);
void dijkstra(int node)
{
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto ele : graph[v])
        {
            int nn = ele.first;
            int nw = ele.second;
            if (dist[nn] > dist[v] + nw)
            {
                dist[nn] = dist[v] + nw;
                q.push(nn);
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
    {
        cout << dist[i] << "\n";
    }
}