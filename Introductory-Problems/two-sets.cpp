#include<bits/stdc++.h>
using namespace std; 


int main() {
    int n; 
    cin >> n; 

    if(n == 3){
        cout << "YES" << endl; 
        cout << 1 << endl; 
        cout << 3 << endl; 
        cout << 2 << endl; 
        cout << 1 << " " << 2 << endl; 
        return 0; 
    }

    if(n%4 == 0){
        cout << "YES" << endl; 
        vector<int>firsts; 
        vector<int>seconds;
        for(int i=1; i<=n; i++) {
            if (i%4 == 0 || i%4 == 1) firsts.push_back(i);
            else seconds.push_back(i); 
        }

        cout << firsts.size() << endl; 
        for (auto c : firsts) cout << c << " ";
        cout << endl; 
        cout << seconds.size() << endl; 
        for (auto c : seconds) cout << c << " "; 
        cout << endl;
    }else if (n%4 == 3) {
        cout << "YES" << endl; 
        vector<int>firsts; 
        vector<int>seconds;
        
        firsts.push_back(1); 
        firsts.push_back(2);
        seconds.push_back(3);

        for(int i=4; i<=n; i++){
            if(i%4 == 0 || i%4 == 3) firsts.push_back(i);
            else seconds.push_back(i);
        }

        cout << firsts.size() << endl; 
        for(auto c : firsts) cout << c << " ";
        cout << endl; 
        cout << seconds.size() << endl; 
        for(auto c : seconds) cout << c << " ";
        cout << endl; 
    }else{
        cout << "NO" << endl; 
    }
    return 0; 
}



// 1 , 2 , 3 , 4
// n, n + 1, n + 2, n + 3, n + 4

// 1 2 3 4 5 6 
// n%4 == 0, 3 then solution exists 

// 1 2 3 4 5 6 7 8 

// 5 8 4 1  |   2 3 6 7 

// n + n + 3 = n + 1 + n + 2 

// 1 2 3 4 5 6 7