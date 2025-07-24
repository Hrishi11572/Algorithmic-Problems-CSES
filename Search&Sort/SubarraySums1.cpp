/*
    Given an array of n positive integers, your task is to count the number of subarrays having sum x.
*/
#include<bits/stdc++.h>
using namespace std;
using lli = long long ;
#define endl '\n'
#define MOD 1000000007

int n ;
vector<lli>arr ;

void solve() {
   cin >> n ; 

   lli x ; 
   cin >> x ; 

   arr.resize(n);
   for(int i=0;i<n ;i++){
        cin >> arr[i];
   }

   lli ans = 0 ; 

   vector<lli>prefix(n+1);

   prefix[0] = 0;
   for(int i=1 ;i<=n ; i++){
        prefix[i] = prefix[i-1] + arr[i-1];
   }

   // how do i count such pairs (L,R)
   // prefix[R] - prefix[L-1] == x --> prefix[R] = x + prefix[L-1](=prefix[i])
    map<lli,lli>mp ; 

   for(int i=0 ; i<=n ; i++){
        if(mp[prefix[i]] != 0){ // already seen this element 
            ans+=1ll; 
        }
        mp[x + prefix[i]]++ ;
   }

    cout << ans << endl ; 
}

signed main() {
 ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

//   int _t; cin >> _t; while(_t--)
   solve();
}

/*
    array : 2 4 1 2 7 ; x = 7

    prefarray : 0 2 6 7 9 16 ; x = 7 

    just need to count two pointers, such that prefix[R] - prefix[L-1] == x || count all such pairs (L,R)

*/