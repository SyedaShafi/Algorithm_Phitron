#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 1;
char grid[N][N];
bool vis[N][N];
int dist[N][N];
int n, m;
vector<pair<int, int>> direct = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
bool isValid(int i, int j)
{
    return (i >= 0 and i < n and j >= 0 and j < m);
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dist[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int u = par.first;
        int v = par.second;
        for (auto ele : direct)
        {
            int ni = u + ele.first;
            int nj = v + ele.second;
            if (isValid(ni, nj) and !vis[ni][nj])
            {
                vis[ni][nj] = true;
                q.push({ni, nj});
                dist[ni][nj] = dist[u][v] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int si, sj, di, dj;
    cin >> si >> sj;
    cin >> di >> dj;

    bfs(si, sj);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}