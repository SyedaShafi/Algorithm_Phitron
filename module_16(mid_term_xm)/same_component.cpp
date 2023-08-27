#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 7;
char grid[N][N];
bool vis[N][N];
int n, m;
vector<pair<int, int>> direct = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool isValid(int i, int j)
{
    return (i >= 0 and i < n and j >= 0 and j < m);
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (auto ele : direct)
    {
        int ni = si + ele.first;
        int nj = sj + ele.second;
        if (isValid(ni, nj) and !vis[ni][nj] and grid[ni][nj] == '.')
        {
            dfs(ni, nj);
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
    cin >> si >> sj >> di >> dj;

    dfs(si, sj);
    if (vis[di][dj])
        cout << "YES\n";
    else
        cout << "NO\n";
}