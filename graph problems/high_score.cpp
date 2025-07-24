#include<bits/stdc++.h>
using namespace std; 
using lli = long long; 

struct Edges{
    int u , v ; lli w;    
};

bool dfs(vector<vector<pair<lli,lli>>> &reverse_graph , int n , vector<int> &vis , vector<int>& changed){
    if(changed[n] ==1){
        return true;
    }
    
    vis[n] = 1; 
    
    for(auto v : reverse_graph[n]){
        if(!vis[v.first]){
            if(dfs(reverse_graph , v.first , vis , changed)) return true; 
        }
    }
    
    return false;
}


signed main(){
    int n , m ; 
    cin >> n >> m ;

    vector<Edges>edge(m);
    vector<vector<pair<lli,lli>>>reverse_graph; 
    vector<lli>dist(n+1 , LLONG_MIN); 
    
    reverse_graph.resize(n+1);
    for(int i=0 ; i<=m-1; i++){
        int a , b ; lli c;  
        cin >> a >> b >> c ;
        edge[i].u = a ; 
        edge[i].v = b ; 
        edge[i].w = c ;
        
        reverse_graph[b].push_back({a,c}); 
    }
    
    dist[1] = 0 ;
     
    int x; 
    for(int i=1 ; i<=n-1 ; i++){
        for(auto e : edge){
            if(dist[e.u] > LLONG_MIN){
                if(dist[e.v] < (dist[e.u] + e.w)){
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }
    }
    vector<int>changed(n+1,0);
    
    for(auto e : edge){
        if(dist[e.u] > LLONG_MIN){
            if(dist[e.v] < (dist[e.u] + e.w)){
                dist[e.v] = dist[e.u] + e.w;
                changed[e.v] = 1; 
            }
        }
    }
     
    vector<int>vis(n+1 , 0); 
    bool check = dfs(reverse_graph , n , vis , changed); // does the changed nodes appear
    // int the path from node n
  
    if(check){
        cout << -1 << endl ; 
    }else{
        cout << dist[n] << endl ; 
    }
}