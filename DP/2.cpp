// Created on : 24 july 2025 

#include<bits/stdc++.h>
using namespace std; 
using lli = long long; 

vector<int>dp; 

int rec(int targetSum, vector<int>& Coins){
    if(targetSum < 0){
        return 1e9; // invalid choice DONT USE INT_MAX, as a simple +1 will lead to out of bounds and wrong answer
    }
    if(targetSum == 0){
        return 0; 
    }

    if(dp[targetSum] != -1) return dp[targetSum]; 

    int minCost = 1e9; 
    for(auto value : Coins){ // explore all options and decide which one feels better 
        minCost = min(minCost , 1 + rec(targetSum - value, Coins)); 
    }

    return dp[targetSum] = minCost ; 
}

int main(){
    int numberOfCoins, targetSum; 
    cin >> numberOfCoins >> targetSum ; 

    vector<int>Denominations(numberOfCoins); 
    for(int i=0; i<numberOfCoins; i++){
        cin >> Denominations[i]; 
    }

    // minimum number of coins needed to create the desired sum or -1 if not possible 
    dp.assign(targetSum + 1 , -1); 

    lli ans = rec(targetSum, Denominations); 
    if(ans == 1e9){
        cout << -1 << endl; 
    }else{
        cout << ans << endl; 
    }
    return 0;
}

