#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
// complexity O(2^n)
int fibo(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
}