#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e4 + 1;
vector<string> graph;
bool vis[N][N];
int n, m, si, sj, di, dj;
int level[N][N];
vector<pair<int, int>> direct = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool isValid(int i, int j)
{
    return (i >= 0 and i < n and j >= 0 and j < m);
}
void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    level[i][j] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int u, v;
        u = par.first;
        v = par.second;
        for (auto ele : direct)
        {
            int ni, nj;
            ni = u + ele.first;
            nj = v + ele.second;
            if (isValid(ni, nj) and !vis[ni][nj] and graph[ni][nj] != 'x')
            {
                q.push({ni, nj});
                vis[ni][nj] = true;
                level[ni][nj] = level[par.first][par.second] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        graph.push_back(st);
        for (int j = 0; j < m; j++)
        {
            if (st[j] == 's')
                si = i, sj = j;
            if (st[j] == 'e')
                di = i, dj = j;
        }
    }
    bfs(si, sj);

    if (level[di][dj] == 0)
        cout << -1 << "\n";
    else
        cout << level[di][dj] << "\n";
}