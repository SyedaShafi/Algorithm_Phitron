#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> graph[N];
int vis[N];
int dist[N];
vector<vector<int>> cmp;
vector<int> tmp;
void dfs(int node)
{
    tmp.push_back(node);
    vis[node] = true;
    for (auto ele : graph[node])
    {
        if (!vis[ele])
        {

            dfs(ele);
        }
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
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cmp.push_back(tmp);
            tmp.clear();
            cnt++;
        }
    }
    cout << "Total component: " << cnt << "\n";
    int i = 1;
    for (auto ele : cmp)
    {
        cout << "Component " << i << ": ";
        for (int e : ele)
        {
            cout << e << " ";
        }
        cout << "\n";
        i++;
    }
}