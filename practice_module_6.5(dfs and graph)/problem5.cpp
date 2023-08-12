#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> graph[N];
bool vis[N];
int height[N];
void dfs(int node)
{
    vis[node] = true;
    for (int child : graph[node])
    {
        if (!vis[child])
        {
            dfs(child);
            height[node] = max(height[child] + 1, height[node]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int node;
    cin >> node;
    dfs(1);
    cout << "Height " << node << " : " << height[node] << "\n";
}