#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
void divide(int a[], int l, int r)
{
    // if (l == r)
    //     return;
    for (int i = l; i <= r; i++)
        cout << a[i] << " ";
    cout << "\n";
    if (l < r)
    {
        int mid = (l + r) / 2;
        divide(a, l, mid);
        divide(a, mid + 1, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    divide(a, 0, n - 1);
}