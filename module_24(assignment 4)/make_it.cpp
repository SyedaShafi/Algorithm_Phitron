#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 5;
int dp[N];
bool make_it(int n, int i)
{
    if (i == n)
        return true;
    if (i > n)
        return false;
    if (dp[i] != -1)
        return dp[i];
    bool op1 = make_it(n, i + 3);
    bool op2 = make_it(n, i * 2);
    return dp[i] = op1 || op2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        if (make_it(n, 1))
            cout
                << "YES\n";
        else
            cout << "NO\n";
    }
}