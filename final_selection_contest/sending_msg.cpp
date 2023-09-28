#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e7 + 1;
int main()
{
    string w1, w2;
    while (cin >> w1 >> w2)
    {
        int j = 0;
        for (int i = 0; i < w1.size(); i++)
        {
            if (w1[i] == w2[j])
            {
                j++;
            }
        }

        if (j == w2.size())
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}