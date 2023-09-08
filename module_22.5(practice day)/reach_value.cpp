#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
bool reached(ll n, ll t)
{
    if (n == t)
        return true;
    if (n < t)
        return false;
    bool f1 = reached(n, t * 10);
    bool f2 = reached(n, t * 20);
    return f1 || f2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (reached(n, 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}