#include <bits/stdc++.h>
using namespace std; 
using lli = long long; 
#define MOD 1000000007 

vector<vector<char>> board; 
vector<vector<lli>> dp;

lli rec(int i , int j){
    // number ways to reach (i, j) 
    if(i < 0 || j < 0) return 0; 
    if(board[i][j] == '*') return 0;
    if(i == 0 && j == 0) return 1;
    
    if(dp[i][j] != -1) return dp[i][j]; 

    int ans = (rec(i-1 , j) + rec(i , j-1))% MOD; 

    return dp[i][j] = ans; 
}

int main(){
    int n ;
    cin >> n ; 

    board.assign(n+1 , vector<char>(n+1, '.')); 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c;
            cin >> c; 
            board[i][j] = c; 
        }
    }

    dp.assign(n+1 , vector<lli>(n + 1 , -1)); 
    cout << rec(n-1,n-1) << endl; 
}