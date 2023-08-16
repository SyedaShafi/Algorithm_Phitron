#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> graph[N];
bool vis[N];
int parent[N];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    parent[node] = -1;
    vis[node] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : graph[par])
        {
            if (vis[child])
                continue;
            parent[child] = par;
            vis[child] = true;
            q.push(child);
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

    bfs(1);

    vector<int> path;
    int cur = n;
    bool f = false;
    while (cur != -1)
    {
        if (cur == 0)
        {
            f = true;
            break;
        }
        path.push_back(cur);
        cur = parent[cur];
    }
    if (f)
        cout << "IMPOSSIBLE\n";
    else
    {
        cout << path.size() << "\n";
        reverse(path.begin(), path.end());
        for (int ele : path)
            cout << ele << " ";
    }
}