#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 1;
vector<string> graph;
bool vis[N][N];
pair<int, int> parent[N][N];
int level[N][N];
int n, m, si, sj, di, dj;
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
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int u, v;
        u = par.first, v = par.second;
        for (auto ele : direct)
        {
            int ni, nj;
            ni = u + ele.first, nj = v + ele.second;
            if (isValid(ni, nj) and !vis[ni][nj] and graph[ni][nj] != 'x')
            {
                q.push({ni, nj});
                level[ni][nj] = level[u][v] + 1;
                parent[ni][nj] = {u, v};
                vis[ni][nj] = true;
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
        cout << -1 << '\n';
    else
    {
        cout << level[di][dj] << "\n";

        pair<int, int> cur = {di, dj};
        vector<pair<int, int>> path;
        while (cur.first != si || cur.second != sj)
        {
            path.push_back(cur);
            cur = parent[cur.first][cur.second];
        }
        
        path.push_back({si, sj});
        reverse(path.begin(), path.end());

        // for (auto ele : path)
        // {
        //     cout << ele.first << " " << ele.second << "\n";
        // }
        for (int i = 1; i < path.size(); i++)
        {
            if (path[i - 1].first == path[i].first)
            {
                // left right movement
                if (path[i - 1].second + 1 == path[i].second)
                {
                    cout << "R";
                }
                else
                    cout << "L";
            }
            else
            {
                // up down movement
                if (path[i - 1].first + 1 == path[i].first)
                {
                    cout << "D";
                }
                else
                    cout << "U";
            }
        }
    }
}