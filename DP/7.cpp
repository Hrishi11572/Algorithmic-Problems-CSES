// Book Shop :: Solved on 25 July 2025 
// #include <bits/stdc++.h>

// using namespace std;

// // TC : O(N*X) = 10^8 operations in 1 sec => TLE 
// // convert code to iterative code 

// int n;
// vector<int>price; 
// vector<int>pages; 
// vector<vector<int>> dp; 

// int rec(int level , int maxTotalPrice){
//     // base case
//     if(maxTotalPrice < 0){
//         return -1e9; // invalid choice
//     } 
//     if(level == n){
//         return 0; // end of the level 
//     }

//     // cache 
//     if(dp[level][maxTotalPrice] != -1) return dp[level][maxTotalPrice];

//     // transition 
//     // take this book 
//     int ans = pages[level] + rec(level + 1, maxTotalPrice - price[level]); 
//     // leave this book 
//     ans = max(ans , rec(level + 1 , maxTotalPrice));  

//     // store the answer and return 
//     return dp[level][maxTotalPrice] = ans;  
// }

// int main() {
//     int maxTotalPrice; 
//     cin >> n >> maxTotalPrice; 

//     for(int i=1;i<=n; i++){
//         int p; cin >> p; 
//         price.push_back(p);
//     }    
//     for(int i=1; i<=n; i++){
//         int p; cin >> p; 
//         pages.push_back(p);
//     }

//     dp.assign(n+1 , vector<int>(maxTotalPrice+1, -1));
//     cout << rec(0, maxTotalPrice) << endl; 
// }


// ITERATIVE CODE :: 

#include <bits/stdc++.h>
using namespace std; 


int main(){
    int n ; 
    int maxTotalPrice; 
    cin >> n >> maxTotalPrice; 
    
    vector<int>price(n + 10); 
    vector<int>pages(n + 10); 
    
    
    for(int i=1; i<=n; i++){ 
        cin >> price[i];
    }
    for(int i=1; i<=n; i++){
        cin >> pages[i];
    }
    
    vector<vector<int>> dp(n+10, vector<int>(maxTotalPrice+10 ,0)); 
    
    for(int i=n; i>=1; i--){
        for(int currPrice=0; currPrice<=maxTotalPrice; currPrice++){
            if(currPrice-price[i] >= 0){
                dp[i][currPrice] = pages[i] + dp[i+1][currPrice-price[i]]; 
            }
            dp[i][currPrice] = max(dp[i][currPrice] , dp[i+1][currPrice]); 
        }
    }
    
    cout <<  dp[1][maxTotalPrice] << endl; 
}
