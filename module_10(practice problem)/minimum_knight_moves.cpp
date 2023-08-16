#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 10 + 1;
int level[N][N];
bool vis[N][N];
vector<pair<int, int>> direc = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

bool isValid(int i, int j)
{
    return (i >= 0 and i < 8 and j >= 0 and j < 8);
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

            if (isValid(ni, nj) and !vis[ni][nj])
            {
                level[ni][nj] = level[i][j] + 1;
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }
}

void reset_level_vis()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            vis[i][j] = false;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        int si, sj, di, dj;
        si = x[0] - 'a';
        sj = x[1] - '1';
        di = y[0] - 'a';
        dj = y[1] - '1';
        // cout << si << " " << sj << " " << di << " " << dj << "\n";
        bfs(si, sj);
        cout << level[di][dj] << "\n";
        reset_level_vis();
    }
}