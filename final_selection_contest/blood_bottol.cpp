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
        string s;
        cin >> s;
        int cnt = 0;
        vector<int> ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                cnt++;
            else if (s[i] == '0' and cnt > 0)
            {
                ans.push_back(cnt);
                cnt = 0;
            }
        }
        if (cnt > 0)
            ans.push_back(cnt);
        sort(ans.rbegin(), ans.rend());
        // for (int i = 0; i < ans.size(); i++)
        //     cout << ans[i] << " ";
        // cout << "\n";
        int zaza = 0;

        for (int i = 0; i < ans.size(); i += 2)
        {
            zaza += ans[i];
        }
        cout << zaza << "\n";
    }
}