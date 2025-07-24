#include<bits/stdc++.h>
using namespace std; 

int n , m;
vector<vector<int>>g ; 
vector<int>vis;
vector<int>ans ; 

signed main(){
    
    cin >> n >> m ; 
    g.resize(n+1);
    vis.assign(n+1,0);
    
    for(int i=0; i<m ; i++){
        int a , b;
        cin >> a >> b; 
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int st=1; 
    vector<int>dist(n+1, 1e9);
    vector<int>parent(n+1,-1);
    
    queue<int>q;
    q.push(1);
    dist[1]=0; 
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        if(vis[node]) continue;
        vis[node]=1;
        
        for(auto v : g[node]){
            if(dist[v] > dist[node] + 1){
                dist[v] = dist[node] + 1; 
                q.push(v);
                parent[v]=node;
            }
        }
    }
    
    if(dist[n] == 1e9){
        cout << "IMPOSSIBLE" << endl ;
    }else{
        cout << dist[n] + 1 << endl ;
        vector<int>path;
        
        int i=n; 
        path.push_back(n);
        while(parent[i] != -1){
            path.push_back(parent[i]);
            i = parent[i];
        }
        
        reverse(path.begin() , path.end());
        
        for(auto c : path){
            cout << c << " ";
        }
        cout << endl ; 
    }
}