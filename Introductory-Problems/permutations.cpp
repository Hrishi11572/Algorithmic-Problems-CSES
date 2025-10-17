#include<bits/stdc++.h>
using namespace std; 
using lli = long long; 

int main() {
    int n;
    cin >> n ; 

    if (n == 1) cout << 1 << endl; 
    else if (n <= 3) cout << "NO SOLUTION" << endl; 
    else if (n == 4) {
        cout << 2 << " " << 4 << " " << 1 << " " << 3 << endl; 
    }else {
        // append numbers to this perm. 2 4 1 3, atlernatively at the start and the end
        deque<int>dq = {2 , 4 , 1 , 3};
        bool flag=0; 
        for(int i=1; i + 4<=n; i++){
            if(flag == 1) { dq.push_back(4+i); flag = 1 - flag;}
            else { dq.push_front(4 + i); flag = 1 - flag; }
        }

        // print the deque 
        for(auto it : dq){
            cout << it << " " ; 
        }
        cout << endl; 
    }
    return 0; 
}