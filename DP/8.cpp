// Problem : Array Description :: Solved on 25 July 2025

#include<bits/stdc++.h>
using namespace std; 
#define MOD 1000000007 

int n , m ; 
vector<int>arr; 
vector<vector<int>> dp; 

int rec(int level, int prev){
    if(prev < 1 || prev > m) return 0; 
    if(level == n){
        return 1; 
    }
    
    // caching 
    if(dp[level][prev] != -1) return dp[level][prev]; 
    
    // transition
    int ans = 0; 
    if(arr[level] == 0){
        for(int i=prev-1; i<=prev+1; i++){
            ans = (ans + rec(level+1, i))%MOD; 
        }
    }else{
        if(abs(arr[level]-prev) <= 1){
            ans = (ans + rec(level+1, arr[level]))%MOD; 
        }
    }    
    return dp[level][prev] = ans; 
}


int main(){
    cin >> n >> m ; 
    
    arr.resize(n); 
    for(int i=0; i<n ; i++){
        cin >> arr[i]; 
    }
    
    dp.assign(n+1, vector<int>(m+1, -1)); 
    
    // separate handling of index = 0
    if(arr[0] != 0)
        cout << rec(0,arr[0]) << endl;
    else {
        int ans=0; 
        for(int i=1; i<=m; i++){
            ans = (ans + rec(1 , i))%MOD; 
        }
        cout << ans << endl; 
    }
    return 0;
}