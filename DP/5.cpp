// Created on 24 July 2025 :: Removing Digits 

#include <bits/stdc++.h>
using namespace std; 

vector<int>dp ;

int rec(int value){
    if(value < 0) return 1e9; 
    if(value == 0){
        return 0; 
    }

    if(dp[value] != -1) return dp[value]; 

    // can subtract any of the digits 
    int temp = value; 
    int ans = 1e9; 
    vector<int> digits; 

    while(temp > 0){
        digits.push_back(temp%10);     
        temp /= 10; 
    }

    for(auto v : digits){
        if(v == 0) continue; 
        ans = min(ans , 1 + rec(value - v)); 
    }

    return dp[value] = ans; 
}


int main(){
    int n; 
    cin >> n ; 
    dp.assign(n+1, -1); 
    cout << rec(n) << endl; 
}