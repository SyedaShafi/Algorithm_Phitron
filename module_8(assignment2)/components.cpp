#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 7;
vector<int> comp;
vector<int> graph[N];
int cnt = 0;
bool vis[N];
void dfs(int node)
{
    cnt++;
    vis[node] = true;
    for (int child : graph[node])
    {
        if (vis[child])
            continue;
        dfs(child);
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

    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            cnt = 0;
            dfs(i);
            comp.push_back(cnt);
        }
    }
    sort(comp.begin(), comp.end());
    for (int ele : comp)
    {
        if (ele > 1)
            cout << ele << " ";
    }
}