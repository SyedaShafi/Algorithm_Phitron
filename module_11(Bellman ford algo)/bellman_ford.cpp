#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
const int INF = INT_MAX;
vector<pair<int, int>> graph[N];
vector<int> dist(N, INF);
int n, m;
void bellman_ford(int node)
{
    dist[node] = 0;
    for (int i = 1; i < n; i++) // n-1 time relaxation
    {
        for (int u = 1; u <= n; u++) // each node er access
        {
            for (auto pr : graph[u]) // u er sob child access
            {
                int v = pr.first;
                int w = pr.second;

                if (dist[u] != INF and dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    bellman_ford(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Dist of " << i << ": ";
        cout << dist[i] << "\n";
    }
}