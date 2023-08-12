#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
int main()
{
    int n, m;
    cin >> n;
    int nums1[n + 1];
    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    cin >> m;
    int nums2[m + 1];
    for (int i = 0; i < m; i++)
        cin >> nums2[i];
    int res[n + m];
    int lp = 0, rp = 0, k = 0;
    while (lp < n and rp < m)
    {
        if (nums1[lp] >= nums2[rp])
        {
            res[k] = nums1[lp];
            lp++;
        }
        else
        {
            res[k] = nums2[rp];
            rp++;
        }
        k++;
    }
    while (lp < n)
    {
        res[k] = nums1[lp];
        lp++;
        k++;
    }
    while (rp < m)
    {
        res[k] = nums2[rp];
        rp++;
        k++;
    }
    for (int i = 0; i < n + m; i++)
        cout << res[i] << " ";
    cout << "\n";
}