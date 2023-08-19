#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e4 + 1;
vector<string> graph;
int n, m, si, sj, di, dj;
vector<pair<int, int>> direct = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[N][N];
int depth[N][N];
bool isValid(int i, int j)
{
    return (i >= 0 and i < n and j >= 0 and j < m);
}
void dfs(int i, int j)
{
    vis[i][j] = true;
    for (auto ele : direct)
    {
        int ni, nj;
        ni = i + ele.first;
        nj = j + ele.second;
        if (isValid(ni, nj) and !vis[ni][nj] and graph[ni][nj] != 'x')
        {
            depth[ni][nj] = depth[i][j] + 1;
            dfs(ni, nj);
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
    dfs(si, sj);
    if (depth[di][dj] > 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}