#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
vector<int> graph[1000];
bool vis[1000];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while (q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int ele : graph[parent])
        {
            if (!vis[ele])
            {
                q.push(ele);
                vis[ele] = true;
            }
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
}