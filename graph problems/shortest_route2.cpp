#include<bits/stdc++.h>
using namespace std; 
using lli = long long; 

signed main(){
    int n , m ,q ; 
    cin >> n >> m >> q ;
    
    vector<vector<lli>>dist(n+1 , vector<lli>(n+1 , 1e18)); 
    
    for(int i=0 ; i<m ; i++){
        int a , b ; 
        lli c ; 
        cin >> a >> b >> c; 
        dist[a][b] = min(dist[a][b] , c);
        dist[b][a] = dist[a][b]; 
    }
    
    for(int i=0 ; i<=n ; i++) dist[i][i] = 0 ; 
    
    for(int k=1 ; k<=n ; k++){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                 if(dist[i][k] != 1e18 && dist[k][j]!= 1e18)
                 dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]); 
            }
        }
    }
    
    for(int i=1 ; i<=q ; i++){
        int a , b; 
        cin >> a >> b ; 
        
        if(dist[a][b] == 1e18){
            cout << -1 << endl ; 
        }else{
            cout << dist[a][b] << endl ; 
        }
    }
}