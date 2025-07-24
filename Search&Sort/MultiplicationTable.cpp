#include<bits/stdc++.h>
using namespace std;
using lli = long long ;
#define endl '\n'
#define MOD 1000000007

lli n ;

// lli arr[1001000];
// lli brr[1001000];  
 // arr = {1 ,2 , 3, 4 , 5 , 6 ... n}
 // brr = {1 ,2 , 3, 4 , 5 , 6 ... n}
 
 // THIS APPROACH GIVES TLE : O(n * logn^2)
// bool check(lli mid){
//     // if the number of elements <= mid are >= n*n/2 then this can be a possible answer 
//     //arr[i] * brr[j] <= mid 
//     //brr[j] <= mid/arr[i] 
    
//     lli ans = 0 ;
//     for(int i=0 ; i<n ; i++){
//         ans += (upper_bound(brr, brr+n , mid/arr[i]) - brr); // gives number of elements <= key
//     }

//     if( ans >= (n*n + 1)/2) return true ;
//     else return false ;
// }

bool check(lli mid){
    // imagine the multiplication table, we iterate over each row and for each row number 
    // we find the number of columns having numbers <= mid , by finding min(n , mid/row_number)
    // say mid = 20,n=5 : so in row1 , all 5 are less = min(5 , 20/1) , in row5 , {1,2,3,4} column numbers when multiplied by 5 
    // consitute a number <= mid 

    lli ans = 0 ;
    for(int i=1; i<=n ; i++){
        ans += min<lli>(n , mid/(i));
    }

    if(ans >= (n*n + 1)/2) return true ; 
    else return false ;
}

void solve() {
    cin >> n ;

//   for(int i=0; i<n ; i++){
//         arr[i] = i+1;
//         brr[i] = i+1;
//   }

   lli lo = 1 ; 
   lli hi = n*n*1LL ;
   lli ans = -1;

   while(lo <= hi){
        lli mid = lo + (hi - lo)/2 ; 
        if(check(mid)){
            ans = mid ; 
            hi = mid-1 ;
        }else{
            lo = mid+1 ; 
        }
   }

   cout << ans << endl ; 
}

signed main() {
 ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
   solve();
}

//     1   2   3   4   5 

// 1   1   2   3   4   5

// 2   2   4   6   8   10

// 3   3   6   9   12  15

// 4   4   8   12  16  20

// 5   5   10  15  20  25

// total elements = 25 

// 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 6, 8, 8, 9, 10, 10, 12, 12, 15, 15, 16, 20, 20, 25
