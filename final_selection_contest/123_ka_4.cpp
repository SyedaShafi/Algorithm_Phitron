#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1)
                cout << j;
            else if (j == 1)
                cout << i;
            else if (j == n)
                cout << n;
            else if (i == n)
                cout << n;
            else
                cout << " ";
        }
        cout << "\n";
    }
}