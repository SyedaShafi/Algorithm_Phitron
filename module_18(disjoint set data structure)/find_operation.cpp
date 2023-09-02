// find the leader(which is approaching towards leader)
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
int parent[8] = {-1, -1, 1, 1, 6, 4, -1, -1};

int find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
int main()
{
    cout << find(2);
}