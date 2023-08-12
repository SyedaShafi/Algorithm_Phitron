#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3 + 1;
int matrix[N][N];
vector<int> adj_list[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
            {
                adj_list[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for (int child : adj_list[i])
        {
            cout << child << " ";
        }
        cout << "\n";
    }
}