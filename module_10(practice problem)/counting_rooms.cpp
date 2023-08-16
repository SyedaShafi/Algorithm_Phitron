#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 5;
int n, m;
char graph[N][N];
bool vis[N][N];
vector<pair<int, int>> direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool isValid(int i, int j)
{
    return (i >= 0 and j >= 0 and i < n and j < m);
}
void dfs(int i, int j)
{
    if (!isValid(i, j))
        return;
    if (vis[i][j])
        return;
    vis[i][j] = true;
    for (auto d : direc)
    {
        dfs(i + d.first, j + d.second);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == '#')
                vis[i][j] = true;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}