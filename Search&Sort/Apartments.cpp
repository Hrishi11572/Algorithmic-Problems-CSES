#include<bits/stdc++.h>
using namespace std;
using lli = long long ;
#define endl '\n'
#define MOD 1000000007

void solve() {
    lli n , m ; 
    cin >> n >> m ; 

    lli k ; cin >>  k ; 

    vector<lli>apartments , desired ;

    // apartments sizes available . n available
    for(int i=0 ; i<n ; i++){
        lli x ; cin >> x ; 
        apartments.push_back(x);
    }   

    // Desired apartment sizes by each person . m applicants
    for(int i=0 ; i<m ; i++){
        lli y ; cin >> y ; 
        desired.push_back(y);
    }

    // Print one integer: the number of applicants who will get an apartment.
    sort(apartments.begin() , apartments.end()) ;
    sort(desired.begin() , desired.end()) ;

    lli ans = 0 ; 

    int i = 0 ; 
    int j = 0 ; 

    while(i < n and j < m){
        if(i >= n || j>=m) break; 
        if(abs(apartments[i] - desired[j]) <= k){
            ans++ ; 
            ++i ; 
            ++j ; // this applicant got one
        }else{
            if(desired[j] + k < apartments[i]){
                j++ ; // isko nhi milega 
            }else if(desired[j] - k > apartments[i]){
                i++ ; // look for next bigger apartment 
            }
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

/*
    incorrect approach  - 
   vector<lli>available;
    for(int i=0 ; i<m ; i++){
        lli high = upper_bound(apartments.begin() , apartments.end() , desired[i] + k) - apartments.begin(); 
        lli low = upper_bound(apartments.begin() , apartments.end() , desired[i] - k) - apartments.begin();
        available.push_back(1*(high-low > 0));
    }

    for(int i=0 ; i<m ; i++){
        if(available[i] != 0){
            --available[i];
            ans++ ;
        }
    }

    cout << ans << endl ;

    does n't take into account the availability issue. simply available= 1 does not guarantee availability here 

*/