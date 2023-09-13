#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 and j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int mx = 0, ci, cj;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] > mx)
            {
                mx = dp[i][j];
                ci = i;
                cj = j;
            }
        }
    }
    string ans;
    while (ci != 0 and cj != 0)
    {
        if (a[ci - 1] == b[cj - 1])
        {
            ans += a[ci - 1];
            ci--, cj--;
        }
        else
        {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    cout << mx << "\n";
}