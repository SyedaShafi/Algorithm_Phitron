#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 3;
char grid[3][3];
bool vis[3][3];
bool f = false;
char current_player = 'X';
vector<pair<int, int>> direct = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
bool isValid(int i, int j)
{
    return (i >= 0 and i < 3 and j >= 0 and j < 3);
}
void take_input()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = '_';
        }
    }
}
void print_grid()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
bool node_empty(int i, int j)
{
    if (grid[i][j] == '_')
        return true;
    return false;
}
bool is_game()
{
    bool flag = false;

    if (grid[0][0] != '_' and grid[1][1] != '_' and grid[0][0] == grid[1][1] and grid[1][1] == grid[2][2])
        flag = true;
    else if (grid[0][0] != '_' and grid[0][1] != '_' and grid[0][0] == grid[0][1] and grid[0][1] == grid[0][2])
        flag = true;
    else if (grid[1][0] != '_' and grid[1][1] != '_' and grid[1][0] == grid[1][1] and grid[1][1] == grid[1][2])
        flag = true;
    else if (grid[2][0] != '_' and grid[2][1] != '_' and grid[2][0] == grid[2][1] and grid[2][1] == grid[2][2])
        flag = true;
    else if (grid[0][2] != '_' and grid[1][1] != '_' and grid[0][2] == grid[1][1] and grid[1][1] == grid[2][0])
        flag = true;
    else if (grid[0][0] != '_' and grid[1][0] != '_' and grid[0][0] == grid[1][0] and grid[1][0] == grid[2][0])
        flag = true;
    else if (grid[0][1] != '_' and grid[1][1] != '_' and grid[0][1] == grid[1][1] and grid[1][1] == grid[2][1])
        flag = true;
    else if (grid[0][2] != '_' and grid[1][2] != '_' and grid[0][2] == grid[1][2] and grid[1][2] == grid[2][2])
        flag = true;

    return flag;
}
void dfs(int i, int j)
{
    vis[i][j] = true;
    if (node_empty(i, j))
    {
        grid[i][j] = current_player;
        current_player = (current_player == 'X') ? 'O' : 'X';
        if (is_game())
        {
            f = true;
            print_grid();
            cout << "\n";
        }
        if (f == false)
            print_grid();
        cout << "\n";
    }
    for (auto ele : direct)
    {
        int u = i + ele.first;
        int v = j + ele.second;
        if (f == false and isValid(u, v) and !vis[u][v])
        {
            dfs(u, v);
        }
    }
}
int main()
{
    take_input();
    print_grid();
    cout << "\n";
    dfs(0, 0);
    if (f == false)
        cout << "Draw\n";
    else
        cout << "Game\n";
}