#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 3;
char graph[N][N];
bool vis[N][N];
int level[N][N];
int n, m;
pair<int, int> parent[N][N];
vector<pair<int, int>> direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 and j >= 0 and i < n and j < m);
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int i = par.first;
        int j = par.second;
        for (auto d : direc)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (isValid(ni, nj) and !vis[ni][nj] and graph[ni][nj] != '#')
            {
                q.push({ni, nj});
                level[ni][nj] = level[i][j] + 1;
                vis[ni][nj] = true;
                parent[ni][nj] = {i, j};
            }
        }
    }
}

int main()
{
    int si, sj, di, dj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 'A')
                si = i, sj = j;
            if (graph[i][j] == 'B')
                di = i, dj = j;
        }
    }

    bfs(si, sj);
    if (level[di][dj] != 0)
    {
        cout << "YES\n";
        cout << level[di][dj] << "\n";
        vector<pair<int, int>> path;
        pair<int, int> curr = {di, dj};
        while (!(curr.first == si && curr.second == sj))
        {
            path.push_back(curr);
            curr = parent[curr.first][curr.second];
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
                    cout << "R";
                else
                    cout << "L";
            }
            else
            {
                // up down movement
                if (path[i - 1].first + 1 == path[i].first)
                    cout << "D";
                else
                    cout << "U";
            }
        }
    }
    else
    {
        cout << "NO\n";
    }
}