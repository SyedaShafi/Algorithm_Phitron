#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 7;
vector<int> graph[N];
bool vis[N];
vector<int> con;
void dfs(int node)
{
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
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cnt++;
            con.push_back(i);
        }
    }
    cout << cnt - 1 << "\n";
    for (int i = 0; i < con.size() - 1; i++)
    {
        cout << con[i] << " " << con[i + 1] << "\n";
    }
}