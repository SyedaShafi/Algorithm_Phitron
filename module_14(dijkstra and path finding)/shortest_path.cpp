#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 1;
const int INF = 1e9 + 1;
typedef pair<int, int> pii;
vector<int> graph[N];
bool vis[N];
vector<int> dist(N, INF);
int parent[N];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    parent[node] = -1;
    dist[node] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (auto ele : graph[par])
        {
            if (!vis[ele])
            {
                q.push(ele);
                vis[ele] = true;
                dist[ele] = dist[par] + 1;
                parent[ele] = par;
            }
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
    bfs(1);
    int curr = 5;
    vector<int> path;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    for (int ele : path)
    {
        cout << ele << "\n";
    }
}