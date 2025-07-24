#include<bits/stdc++.h>
using namespace std; 
using lli = long long;

int n ; 
vector<lli>arr ;

signed main(){
    cin >> n ; 

    arr.resize(n) ;
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }

    sort(arr.begin() , arr.end());

    lli mid = arr[n/2];

    lli ans = 0;
    for(int i=0 ; i<n ; i++){
        ans += abs(mid - arr[i]);
    }

    cout << ans << endl ; 
}


/*

    n = 5
    2 3 1 5 2

    1 2 2 3 5 
    mid = 2 
    cost = 1 + 0 + 0 + 1 + 3 = 5 



    1 3 5 100 400 700 1000 ; mid = 100 
    cost = 100-1 + 100-3 + 100-5 + 100-100 + 400-100 + 700-100 + 1000- 100 = 2,091 

    1 3 5 100 .....200........400 700 1000 ; mid = 200
    cost = 200-1 + 200-3 + 200-5 + 400-200 + 700-200 + 1000-200 = 2,091
     

    you realise that these are same!! ---> both give same sum 

*/
