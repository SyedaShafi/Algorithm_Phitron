#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 107 + 1;
const int INF = 1e7 + 1;
int dist[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
            if (dist[i][j] == -1)
            {
                dist[i][j] = INF;
            }
        }
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
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mx = (dist[i][j] != INF) ? mx = max(mx, dist[i][j]) : mx = mx;
            ;
        }
    }
    cout << mx << "\n";
}