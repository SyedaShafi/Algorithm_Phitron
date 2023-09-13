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
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    int i = n, j = m;
    string ans;
    while (i != 0 and j != 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans += a[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";

    return 0;
}