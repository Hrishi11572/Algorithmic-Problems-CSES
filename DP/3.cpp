// Coin Combinations 1 : Created on 24 July 2025 

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
using lli = long long; 

vector<lli>dp; 

lli rec(int targetSum, vector<int>&Denominations){
    if(targetSum < 0) {
        return 0;
    }
    if(targetSum == 0){
        return 1; 
    }

    if(dp[targetSum] != -1) return dp[targetSum]; 

    lli numberOfWays = 0; 
    for(auto v : Denominations){
        numberOfWays = (numberOfWays + rec(targetSum - v, Denominations))%MOD; 
    }

    return dp[targetSum] = numberOfWays; 
}

int main(){
    int n , x; 
    cin >> n >> x; 

    vector<int>C; 
    for(int i=1; i<=n; i++){
        int x ; cin >> x; 
        C.push_back(x); 
    }

    dp.assign(x + 1 , -1); 

    cout << rec(x ,C) << endl;
    return 0; 
}