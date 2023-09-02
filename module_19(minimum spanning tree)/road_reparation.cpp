#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> graph[N];
bool vis[N];

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

class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

void prims(int src, int n)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    Edge ed(src, src, 0);
    pq.push(ed);
    int cnt = 0;
    vector<Edge> edgeList;
    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int a = parent.a;
        int b = parent.b;
        int w = parent.w;
        if (vis[b])
            continue;
        vis[b] = true;
        cnt++;
        edgeList.push_back(parent);
        for (int i = 0; i < graph[b].size(); i++)
        {
            pii child = graph[b][i];
            if (!vis[child.first])
            {
                pq.push({b, child.first, child.second});
            }
        }
    }
    edgeList.erase(edgeList.begin());
    ll s = 0;
    for (Edge val : edgeList)
    {
        // cout << val.a << " " << val.b << " " << val.w << "\n";
        s += (ll)(val.w);
    }

    if (cnt == n)
        cout << s << "\n";
    else
        cout << "IMPOSSIBLE\n";
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
    prims(1, n);
}