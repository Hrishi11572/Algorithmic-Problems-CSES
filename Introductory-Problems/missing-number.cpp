#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main()
{
    int n;
    cin >> n;

    lli x = 0;
    lli sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        sum += x;
    }

    cout << 1LL * n * (n + 1) / 2 - sum << endl;
    return 0;
}