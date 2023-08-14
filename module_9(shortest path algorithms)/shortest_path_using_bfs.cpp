#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> graph[N];
bool vis[N];
int level[N];
int parents[N];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    parents[node] = -1;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : graph[parent])
        {
            if (vis[child])
                continue;
            vis[child] = true;
            q.push(child);
            parents[child] = parent;
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
        graph[v].push_back(u);
    }

    int s, d;
    cin >> s >> d;
    bfs(s);
    cout << "Distance : " << level[d] << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "parent of " << i << " : " << parents[i];
        cout << "\n";
    }
    vector<int> path;
    int current = d;
    while (current != -1)
    {
        path.push_back(current);
        current = parents[current];
    }
    reverse(path.begin(), path.end());
    for (int ele : path)
        cout << ele << " ";
}