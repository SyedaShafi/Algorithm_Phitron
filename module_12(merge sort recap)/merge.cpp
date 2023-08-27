#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
void merge(int a[], int l, int m, int r)
{
    int leftsize = m - l + 1;
    int rightsize = r - m;
    int L[leftsize], R[rightsize];
    int k = 0;
    for (int i = l; i <= m; i++)
    {
        L[k] = a[i];
        k++;
    }
    k = 0;
    for (int i = m + 1; i <= r; i++)
    {
        R[k] = a[i];
        k++;
    }
    int i = 0, j = 0;
    int cur = l;
    while (i < leftsize and j < rightsize)
    {
        if (L[i] <= R[j])
        {
            a[cur] = L[i];
            cur++;
            i++;
        }
        else
        {
            a[cur] = R[j];
            j++;
            cur++;
        }
    }

    while (i < leftsize)
    {
        a[cur] = L[i];
        i++, cur++;
    }
    while (j < rightsize)
    {
        a[cur] = R[j];
        j++, cur++;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge(a, 0, 3, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\n";
    }
}