#include<bits/stdc++.h>
using namespace std; 
using lli = long long ; 

signed main(){
    int n;
    cin >> n ; 
    
    int x[n];
    set<int>st; 
    
    for(int i=0 ; i<n ; i++) {
        cin >> x[i]; 
        st.insert(x[i]);
    }
    
    cout << st.size() << endl ; 
}