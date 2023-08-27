#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 1;
vector<int> graph[N];
bool vis[N];
void dfs(int node)
{
    cout << node << "\n";
    vis[node] = true;
    for (auto ele : graph[node])
    {
        if (!vis[ele])
            dfs(ele);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);
}