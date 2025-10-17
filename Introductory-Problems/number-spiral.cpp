#include<bits/stdc++.h>
using namespace std; 
using lli = long long; 

int main() {
    int t; 
    cin >> t; 
    while(t--){
        lli r, c; 
        cin >> r >> c; 
    
        if(r % 2 == 0) {
            // something 
            if (c <= r) {
                // ho jayega 
                cout << r*r - c + 1 << endl; 
            }else {
                if (c % 2 == 1){
                    cout << c*c - r + 1 << endl; 
                }else {
                    cout << c*c - 2 *c + r + 1 << endl; 
                }
            }
        }else {
            // some other thing 
            if (c <= r) {
                // ho jayega 
                cout << (r-1)*(r-1) + c << endl; 
            }else {
                if (c % 2 == 0){
                    cout << c*c - 2 *c + r + 1 << endl; 
                }else{
                    cout << c*c - r  + 1 << endl ;
                }
            }
        }
    }
    return 0; 
}