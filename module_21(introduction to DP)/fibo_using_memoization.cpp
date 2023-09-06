#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e6 + 1;
ll save[N];
ll fibo(int n)
{
    if (n == 0 || n == 1)
        return 1;
    // memoization
    if (save[n] != -1)
        return save[n];

    save[n] = fibo(n - 1) + fibo(n - 2);
    return save[n];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        save[i] = -1;
    }
    // memoization use koray complexity O(N)
    cout << fibo(n);
}