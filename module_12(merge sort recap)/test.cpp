#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
void merge(int a[], int l, int mid, int r)
{
    int leftsize = mid - l + 1;
    int rightsize = r - mid;
    int L[leftsize], R[rightsize];
    int k = 0;
    for (int i = l; i <= mid; i++)
    {
        L[k] = a[i];
        k++;
    }
    k = 0;
    for (int i = mid + 1; i <= r; i++)
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
void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);

        merge(a, l, mid, r);
        cout << l << " " << mid << " " << r << "\n";
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << "\n";
}