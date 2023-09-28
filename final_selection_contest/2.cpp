#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
const int mx = 2e4 + 23;
const ll infll = 900000000000000000;
ll n, cnt, sum = 0;
ll dp[22][mx];
ll val[22];

ll func(ll i, ll s, ll c)
{

    if (c == n / 2)
    {
        ll due = sum - s;

        ll dif = abs(s - due);

        return dif;
    }
    if (i == n + 1)
    {
        if (c == n / 2)
        {
            ll due = sum - s;

            ll dif = abs(s - due);

            return dif;
        }
        else
        {
            return infll;
        }
    }

    ll ret1 = infll, ret2 = infll;

    if (c < n / 2)
    {

        ret1 = func(i + 1, s + val[i], c + 1);
    }

    ret2 = func(i + 1, s, c);

    // dbg(i,s,c,ret1,ret2);
    return dp[i][s] = min(ret1, ret2);
}
int main()
{

    int tc;

    cin >> tc;

    while (tc--)
    {
        memset(dp, -1, sizeof(dp));

        cin >> n;

        cnt = 0;
        sum = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> val[i];
            sum += val[i];
        }

        cout << func(1, 0, 0) << endl;
    }

    return 0;
}