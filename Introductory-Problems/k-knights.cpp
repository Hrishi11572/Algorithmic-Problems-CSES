#include<bits/stdc++.h>
using namespace std; 

using lli = long long; 


int main() {
    lli n; 
    cin >> n ; 
    lli ans = 0; 
    for ( lli k = 1; k<=n ; k++ ){
        ans = ( (1LL*k*k) * (1LL*k*k - 1)/2 ) - 4LL * (k - 1)*(k - 2); 
        cout << ans << endl; 
    }
    return 0;
}