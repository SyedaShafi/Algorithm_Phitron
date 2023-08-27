#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    int dist[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            if (dist[ed.v] > dist[ed.u] + ed.w)
            {
                dist[ed.v] = dist[ed.u] + ed.w;
            }
        }
    }
    bool cycle = false;
    for (int j = 0; j < v.size(); j++)
    {
        Edge ed = v[j];
        if (dist[ed.v] > dist[ed.u] + ed.w)
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
        cout << "Cycle detected\n";
    else
        for (int i = 1; i <= n; i++)
        {
            cout << "Dist of node " << i << ": " << dist[i] << "\n";
        }
}