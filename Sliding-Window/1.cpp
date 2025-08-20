#include <bits/stdc++.h>
using namespace std; 

int main() {
    long long n, k; 
    cin >> n >> k; 

    long long x, a, b, c; 
    cin >> x >> a >> b >> c; 

    vector<long long>arr(n+1); 

    arr[1] = x; 
    for(int i=2; i<=n; i++){
        arr[i] = (a * arr[i-1] + b)%c; 
    }

    long long sum = 0; 
    for(int i=1; i<=k; i++){
        sum += arr[i];
    }

    vector<long long>ans; 
    ans.push_back(sum);

    for(int i=k+1; i<=n; i++){
        sum += (arr[i] - arr[i-k]);
        ans.push_back(sum);
    }

    long long xr = 0; 
    for(int i=0; i<(int)ans.size(); i++){
        xr ^= ans[i];
    }
    cout << xr << endl; 
    return 0; 
}