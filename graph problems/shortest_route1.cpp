#include<bits/stdc++.h>
using namespace std; 
using lli = long long; 

signed main(){
    int n , m ; 
    cin >> n >> m ; 
    
    vector<vector<pair<int,int>>>g; 
    vector<lli>dist(n+1 , 1e18); 
    vector<int>vis(n+1 ,0); 
    g.resize(n+1);
    
    for(int i=0 ; i<m ; i++){
        int a , b ; lli c; 
        cin >> a >> b >> c; 
        
        g[a].push_back({b,c});
    }
    
    priority_queue<pair<lli,int>> q; 
    dist[1] = 0; 
    q.push({0,1}); 
    
    while(!q.empty()){
        auto [w , n] = q.top(); 
        q.pop(); 
        
        if(vis[n]) continue; 
        vis[n] = 1; 
        
        for(auto v : g[n]){
            if(dist[v.first] > dist[n] + v.second){
                dist[v.first] = dist[n] + v.second; 
                q.push({-1*dist[v.first] , v.first});
            }
        }
    }
    
    for(int i=1 ; i<=n ; i++){
        cout << dist[i] << " " ; 
    }
    
}