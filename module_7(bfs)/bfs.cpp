#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> graph[N];
bool visited[N];
int level[N];

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    level[node] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        cout << "Node visited :" << parent << "\n";
        for (int child : graph[parent])
        {
            if (visited[child])
                continue;
            q.push(child);
            visited[child] = true;
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
    bfs(1);

    for (int i = 1; i <= n; i++)
        cout << "level of " << i << " : " << level[i] << "\n";
}