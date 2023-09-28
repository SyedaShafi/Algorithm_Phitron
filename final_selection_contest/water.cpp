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
        int n;
        cin >> n;
        int a[n];
        int tmp[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            tmp[i] = a[i];
        }
        sort(tmp, tmp + n);
        int m = tmp[n - 1];
        int b = tmp[n - 2];
        int x, y;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == m)
            {
                x = i;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b)
            {
                y = i;
                break;
            }
        }
        if (x > y)
            cout << y << " " << x << "\n";
        else
            cout << x << " " << y << "\n";
    }
}