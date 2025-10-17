#include<bits/stdc++.h>
using namespace std; 
using lli = long long; 

int main() {
    int n ; 
    cin >> n; 

    vector<lli>arr(n); 
    for(int i=0; i<n; i++) cin >> arr[i]; 

    lli val=0; 
    for(int i=1;i<n;i++){
        if(arr[i] < arr[i-1]){
            val += abs(arr[i] - arr[i-1]); 
            arr[i] = arr[i-1];
        }
    }   

    cout << val << endl; 
    return 0; 
}

/*
    4 2 1 3 8 3 
    4 4 4 4 8 8 
      2+3+1. +5
    = 11 
*/