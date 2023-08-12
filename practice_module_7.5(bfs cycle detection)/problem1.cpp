#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> graph[N];
bool vis[N];
stack<int> st;
void bfs(int node)
{
    queue<int> q;
    vis[node] = true;
    q.push(node);
    st.push(node);
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : graph[parent])
        {
            if (vis[child])
                continue;
            st.push(child);
            q.push(child);
            vis[child] = true;
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
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}