#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e4 + 1;
typedef pair<int, int> pii;
vector<pii> direct = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
vector<string> graph;
int n, m, si, sj, di, dj;
bool vis[N][N];
int level[N][N];
bool isValid(int i, int j)
{
    return (i >= 0 and i < n and j >= 0 and j < m);
}
void bfs(int i, int j)
{
    queue<pii> q;
    q.push({i, j});
    vis[i][j] = true;
    while (!q.empty())
    {
        pii pr = q.front();
        int u, v;
        u = pr.first;
        v = pr.second;
        q.pop();
        for (auto ele : direct)
        {
            int ni, nj;
            ni = u + ele.first;
            nj = v + ele.second;
            if (isValid(ni, nj) and !vis[ni][nj] and graph[ni][nj] != 'x')
            {
                q.push({ni, nj});
                vis[ni][nj] = true;
                level[ni][nj] = level[u][v] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 's')
                si = i, sj = j;
            if (x[j] == 'e')
                di = i, dj = j;
        }
        graph.push_back(x);
    }
    bfs(si, sj);
    if (level[di][dj] > 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}