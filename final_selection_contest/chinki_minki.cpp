#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n;
const int N = 25;
int total_sum = 0;
int a[N];
int minimum_diff(int i, int s, int c)
{
    if (c == n / 2)
    {
        int res = total_sum - s;
        return abs(res - s);
    }
    if (i == 0)
    {
        if (c == n / 2)
        {
            int res = total_sum - s;
            return abs(res - s);
        }
        else
            return INT_MAX;
    }
    int ans1 = INT_MAX, ans2 = INT_MAX;
    if (c < n / 2)
    {
        ans1 = minimum_diff(i - 1, s + a[i - 1], c + 1);
    }
    ans2 = minimum_diff(i - 1, s, c);

    return min(ans1, ans2);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        total_sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            total_sum += a[i];
        }
        cout << minimum_diff(n, 0, 0) << "\n";
    }
}