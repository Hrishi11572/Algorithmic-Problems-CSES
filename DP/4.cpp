// #include<bits/stdc++.h>
// using namespace std;
// #define MOD 1000000007
// using lli =long long; 
 
// int n ; 
// vector<int>Denominations; 
// vector<vector<lli>>dp; 
 
// // 0-inf knapsack :: ability to choose an index infinite times granted 
// lli rec(lli target , int index){
//     if(target < 0) return 0; 
//     if(target == 0) return 1; 
//     if(index >= n) return 0; 
 
//     if(dp[target][index] != -1) return dp[target][index];   
    
//     // either take this coin any number of times
//     lli ans = rec(target - Denominations[index], index) % MOD; 
 
//     // or don't take it and move ahead 
//     ans = (ans + rec(target , index+ 1)) % MOD; 
 
//     return dp[target][index] = ans; 
// }
 
// int main() { 
//     int numCoins; 
//     int targetSum; 
 
//     cin >> numCoins >> targetSum; 
 
//     n = numCoins; 
 
//     for(int i=0;i<numCoins; i++){
//         int x; cin >> x; 
//         Denominations.push_back(x); 
//     }
 
//     dp.assign(targetSum + 1 , vector<lli>(numCoins + 1 , -1)); 
//     cout << rec(targetSum , 0) << endl; 
// }


// ITERATIVE :: 

#include<bits/stdc++.h>
using namespace std; 

using lli = long long; 

#define MOD 1000000007



int main(){
    int numOfCoins; 
    int targetSum;  
    
    cin >> numOfCoins >> targetSum; 
    vector<int>Denominations(numOfCoins); 
    
    for(int i=0; i<numOfCoins; i++){
        cin >> Denominations[i];
    }
    
    vector<vector<int>>dp (numOfCoins+1 , vector<int>(targetSum + 1, 0)); 
    
    for(int i=numOfCoins; i>=0; i--){
        for(int sumleft=0; sumleft<=targetSum; sumleft++){
            
            if(sumleft == 0) { dp[i][sumleft] = 1; continue; } 
            
            if(i<numOfCoins && sumleft-Denominations[i] >= 0){
                dp[i][sumleft] = (dp[i][sumleft] + dp[i][sumleft-Denominations[i]])%MOD; 
            }
            
            if(i+1 <= numOfCoins){
                dp[i][sumleft] = (dp[i][sumleft] + dp[i+1][sumleft])%MOD;  
            }
        }
    }
    
    cout << dp[0][targetSum] << endl ;
    return 0; 
}