#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e4 + 5;
ll dp[N];
ll coins(ll a[], int n)
{
    if (n < 1)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = max(coins(a, n - 2) + a[n - 1], coins(a, n - 1));
}

int main()
{
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << "Case " << cs << ": " << coins(a, n) << "\n";
        cs++;
    }
}