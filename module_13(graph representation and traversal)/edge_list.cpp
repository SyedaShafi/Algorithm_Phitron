#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> lp;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        lp.push_back({u, v});
    }
    for (int i = 0; i < lp.size(); i++)
        cout << lp[i].first << " " << lp[i].second << "\n";
}