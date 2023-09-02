#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
const int N = 107;
const int INF = 1e7 + 7;
vector<int> dist(N, INF);
vector<Edge> graph;
int n, m;
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        graph.push_back(ed);
    }
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            Edge ed = graph[j];
            if (dist[ed.a] < INF and dist[ed.b] > dist[ed.a] + ed.w)
            {
                dist[ed.b] = dist[ed.a] + ed.w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << 30000 << " ";
        else
            cout << dist[i] << " ";
    }
}