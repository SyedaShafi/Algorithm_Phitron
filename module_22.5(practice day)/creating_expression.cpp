#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
bool expression(int a[], int n, int t, int x)
{
    if (n == 0 and t == x)
        return true;
    if (n == 0)
        return false;
    bool f1 = expression(a, n - 1, a[n - 1] + t, x);
    bool f2 = expression(a, n - 1, a[n - 1] - t, x);
    return f1 || f2;
}
int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool f = expression(a, n, 0, x);
    if (f)
        cout << "YES\n";
    else
        cout << "NO\n";
}