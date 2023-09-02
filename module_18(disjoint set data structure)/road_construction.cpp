#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int mx = 0;
const int N = 1e5 + 5;
int parent[N];
int parentSize[N];
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
            mx = max(mx, parentSize[leader_of_a]);
        }
        else
        {
            parent[leader_of_a] = leader_of_b;
            parentSize[leader_of_b] += parentSize[leader_of_a];
            mx = max(mx, parentSize[leader_of_b]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    dsu_set(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int leader_a = dsu_find(a);
        int leader_b = dsu_find(b);
        if (leader_a != leader_b)
            n--;
        dsu_union_by_size(a, b);
        cout << n << " " << mx << "\n";
    }
}