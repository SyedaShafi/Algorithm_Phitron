#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
int nums[N];
int binary_search(int k, int l, int r)
{
    int mid, ans = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (k == nums[mid])
        {
            ans = mid;
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
    int f = binary_search(k, 0, n - 1);
    if (f == -1)
    {
        cout << "Not Found\n";
    }
    else
        cout << f << "\n";
}