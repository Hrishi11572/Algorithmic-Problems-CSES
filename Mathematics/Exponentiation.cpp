#define _Alignof(type) __alignof__(type)
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
#define MOD 1000000007
void solve()
{
    lli a, b;
    cin >> a >> b;

    lli result = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * a) % MOD;
        }
        b = b >> 1;
        a = (a * a) % MOD;
    }
    cout << result << endl;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
