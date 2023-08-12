#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 100 + 1;
vector<int> graph[N];
bool vis[N];
int level[N];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : graph[parent])
        {
            if (vis[child])
                continue;
            q.push(child);
            vis[child] = true;
            level[child] = level[parent] + 1;
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
    }
    int k;
    cin >> k;
    bfs(k);
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (level[i] > 0)
            cnt++;
    }
    cout << cnt << "\n";
}