#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int diff = 1000 - m;

        ll dp[n + 1][diff + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= diff; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= diff; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = (dp[i][j - a[i - 1]] + dp[i - 1][j]) % mod;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] % mod;
                }
            }
        }
        cout << dp[n][diff] % mod << "\n";
    }
}