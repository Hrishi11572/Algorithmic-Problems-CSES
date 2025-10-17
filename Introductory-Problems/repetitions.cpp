#include<bits/stdc++.h>
using namespace std; 
using lli = long long; 

int main(){
    string s; 
    cin >> s; 

    int j=0; 
    int n = s.length();
    int maxlen=-1; 

    for(int i=0; i<n; i++){
        if(i!=n-1 && s[i] == s[i+1]){
            j = i+1; 
            while(j < n && s[j] == s[j-1]) j++; 
            maxlen = max(maxlen, j-i);
            i = j-1; // take care here, I want i to be equal to j next, so I must set i = j-1 here so that i++ gives i = j 
        }
    }
    if(maxlen == -1) cout << 1 << endl ;
    else cout << maxlen << endl; 

    return 0; 
}