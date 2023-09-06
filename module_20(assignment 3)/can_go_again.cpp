#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
const ll INF = 1e18;
vector<pair<ll, ll>> graph[N];
vector<ll> dist(N, INF);
int n, m;
void bellman_ford(int node)
{
    dist[node] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (auto pr : graph[u])
            {
                ll v = pr.first;
                ll w = pr.second;

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
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    ll s;
    cin >> s;
    bellman_ford(s);
    bool f = false;
    for (int i = 1; i < n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (auto pr : graph[u])
            {
                int v = pr.first;
                int w = pr.second;

                if (dist[u] != INF and dist[v] > dist[u] + w)
                {
                    f = true;
                }
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        if (f)
            continue;
        else if (dist[d] == INF)
            cout << "Not Possible\n";
        else
            cout << dist[d] << "\n";
    }
    if(f)
        cout << "Negative Cycle Detected\n";
}