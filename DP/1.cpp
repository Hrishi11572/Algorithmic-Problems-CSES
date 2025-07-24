// Problem:: Dice Combinations 
#include<bits/stdc++.h>
using namespace std;
using lli = long long;  
#define MOD 1000000007

vector<lli>dp; 

lli rec(int n){
    if(n < 0) return 0; 
    if(n == 0){
        return 1; 
    }

    // cache it 
    if(dp[n] != -1) return dp[n]; 

    lli ans = 0; 
    for(int val = 1; val <= 6 ; val++){
        ans = (ans + rec(n - val)) % MOD; 
    }
    return dp[n] = ans; 
}

int main(){
    int n; 
    cin >> n ; 

    // solve the problem 
    dp.assign(n+1 , -1); 
    cout << rec(n) << endl; 

    return 0; 
}