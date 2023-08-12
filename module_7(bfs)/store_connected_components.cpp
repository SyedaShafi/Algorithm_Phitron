#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> graph[N];
bool vis[N];
vector<vector<int>> connected_components;
vector<int> cc_tmp;
void dfs(int node)
{
    cc_tmp.push_back(node);
    vis[node] = true;
    for (int child : graph[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cc_tmp.clear();
            dfs(i);
            connected_components.push_back(cc_tmp);
        }
    }

    for (int i = 0; i < connected_components.size(); i++)
    {
        cout << "Connected component " << i + 1 << " : ";
        for (int ele : connected_components[i])
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
}