#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 100 + 7;
vector<pair<int, int>> direct = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
int step = 0;
int level[N][N];
bool vis[N][N];
int ki, kj, qi, qj;
int n, m;
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
        pair<int, int> pr = q.front();
        q.pop();
        int u = pr.first;
        int v = pr.second;
        for (auto ele : direct)
        {
            int ni = u + ele.first;
            int nj = v + ele.second;
            if (isValid(ni, nj) and !vis[ni][nj])
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
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cin >> ki >> kj >> qi >> qj;

        bfs(ki, kj);
        if (level[qi][qj] >= 0 and vis[qi][qj])
            cout << level[qi][qj] << "\n";
        else
            cout << -1 << "\n";
        step = 0;
        memset(vis, 0, sizeof(vis));
        memset(level, 0, sizeof(level));
    }
}