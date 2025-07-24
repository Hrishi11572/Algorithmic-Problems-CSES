#include<bits/stdc++.h>
using namespace std ;
using lli = long long ; 

void solve(){
   int n ; cin >> n ; 
   std::vector<lli> arr(n) ;
   
   for(int i=0 ; i<n ; i++){
       cin >> arr[i];
   }
   
   sort(arr.begin() , arr.end());

   lli currentFormableSum = 0ll ; 
   lli ans = 0ll ;
   
   for(int i=0 ; i<n ; i++){
       if(currentFormableSum + 1ll < arr[i]){
           // I can't form currentFormableSum +1 ; 
           break;
       }
        currentFormableSum += arr[i] ;
   }
   
   cout <<  currentFormableSum +1 << endl ; 
}   

signed main(){
    solve();
}
