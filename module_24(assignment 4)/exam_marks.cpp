#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int diff = 1000 - m;

        bool dp[n + 1][diff + 1];
        dp[0][0] = true;
        for (int i = 1; i <= diff; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= diff; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = (dp[i - 1][j - a[i - 1]] || dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][diff])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}