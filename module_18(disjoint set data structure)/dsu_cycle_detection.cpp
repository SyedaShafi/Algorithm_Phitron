#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
int parent[1000];
int parentSize[1000];
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

void union_by_size(int a, int b)
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
    dsu_set(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int leader_of_a = dsu_find(a);
        int leader_of_b = dsu_find(b);
        cout << leader_of_a << " " << leader_of_b << "\n";
        if (leader_of_a == leader_of_b)
        {
            cout << "Cycle detected in between :\n";
            cout << a << " " << b;
            break;
        }
        union_by_size(a, b);
    }
}