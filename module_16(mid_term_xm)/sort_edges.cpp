#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
vector<pair<int, int>> l;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return b.second > a.second;
    return a.first < b.first;
}
int main()
{
    int e;
    cin >> e;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        l.push_back({u, v});
    }
    sort(l.begin(), l.end(), cmp);
    for (auto ele : l)
    {
        cout << ele.first << " " << ele.second << "\n";
    }
}