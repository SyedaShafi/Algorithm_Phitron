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
        int n;
        cin >> n;
        int dif;
        cin >> dif;
        ll s = 0;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }

        ll s1 = (dif + s);
        if (s1 % 2 != 0)
            cout << 0 << "\n";
        else
        {
            s1 /= 2;
            ll dp[n + 1][s1 + 1];
            dp[0][0] = 1;
            for (int i = 1; i <= s1; i++)
            {
                dp[0][i] = 0;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= s1; j++)
                {
                    if (a[i - 1] <= j)
                    {
                        dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j] % mod;
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] % mod;
                    }
                }
            }
            cout << dp[n][s1] % mod << "\n";
        }
    }
}