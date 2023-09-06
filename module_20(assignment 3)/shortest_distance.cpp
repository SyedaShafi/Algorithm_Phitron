#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll INF = 1e18 + 1;
int main()
{
    ll n, e;
    cin >> n >> e;
    ll dist[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
            if (i == j)
                dist[i][j] = 0;
        }
    }
    while (e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = min(w, dist[a][b]);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll s, d;
        cin >> s >> d;
        if (dist[s][d] == INF)
            cout << -1 << "\n";
        else
            cout << dist[s][d] << "\n";
    }
}