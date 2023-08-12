#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
int nums[N];
bool binary_search(int k, int l, int r)
{
    int mid, ans = false;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (k == nums[mid])
        {
            if (mid > 0 and nums[mid - 1] == k)
                ans = true;
            else if (mid < r and nums[mid + 1] == k)
                ans = true;
            break;
        }
        else if (nums[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    bool f = binary_search(k, 0, n - 1);
    if (f)
        cout << "YES\n";
    else
        cout << "NO\n";
}