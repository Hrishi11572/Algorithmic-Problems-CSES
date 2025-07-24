#define _Alignof(type) __alignof__(type)
#include<bits/stdc++.h>
using namespace std;
using lli = long long ;
#define endl '\n'
#define MOD 1000000007

lli binpow(lli a , lli b , lli M){
    lli result = 1LL; 
    a%= M; 
    while(b){
        if(b%2) result = (result * a)%M ; 
        a = (a * a)%M; 
        b/=2 ;
    }
    
    return result ; 
}

void solve() {
   int n ; 
   cin >> n ; 

   // (1378)^n % 10 = (8^n)%10; 
   cout << binpow(8,n,10) << endl; 
}

signed main() {
 ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

   //int _t; cin >> _t; while(_t--)
   solve();
}