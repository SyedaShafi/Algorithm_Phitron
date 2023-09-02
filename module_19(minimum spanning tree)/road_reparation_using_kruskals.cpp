#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 5;

int parent[N];
int parentSize[N];

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

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

void dsu_union_by_size(int a, int b)
{
    int leader_of_a = dsu_find(a);
    int leader_of_b = dsu_find(b);

    if (leader_of_a != leader_of_b)
    {
        if (parentSize[leader_of_a] > parentSize[leader_of_b])
        {
            parent[leader_of_b] = leader_of_a;
            parentSize[leader_of_a] += parentSize[leader_of_b];
        }
        else
        {
            parent[leader_of_a] = leader_of_b;
            parentSize[leader_of_b] += parentSize[leader_of_a];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> v;
    ll ans = 0;
    dsu_set(n);
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 0;
    for (Edge val : v)
    {
        int leader_a = dsu_find(val.a);
        int leader_b = dsu_find(val.b);

        if (leader_a != leader_b)
        {
            ans += (ll)(val.w);
            cnt++;
            dsu_union_by_size(val.a, val.b);
        }
    }
    if (cnt == n - 1)
        cout << ans << "\n";
    else
        cout << "IMPOSSIBLE\n";
}
