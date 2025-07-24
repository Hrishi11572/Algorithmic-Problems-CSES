// bipartite check 

#include<bits/stdc++.h>
using namespace std; 

int n , m;
vector<vector<int>>g ; 
vector<int>vis;
vector<int>ans ; 

signed main(){
    
    cin >> n >> m ; 
    g.resize(n+1);
    vis.assign(n+1,-1);
    
    for(int i=0; i<m ; i++){
        int a , b;
        cin >> a >> b; 
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    bool is_bipartite = true;
    queue<int> q;
    
    for(int i=1 ; i<=n ; i++){
        if(vis[i]==-1){
            q.push(i);
            vis[i]=0; 
            
            while(!q.empty()){
                int x = q.front();
                q.pop();
                
                for(auto v : g[x]){
                    if(vis[v] == -1){
                        vis[v] = vis[x] ^ 1 ; 
                        q.push(v);
                    }else{
                        if(vis[v] == vis[x]){
                            is_bipartite = false;
                        }
                    }
                }
            }
        }
    }
    
    if(is_bipartite == false){
        cout << "IMPOSSIBLE" << endl;
    }else{
        
        for(int i=1 ; i<=n ; i++){
            if(vis[i]==0){
                cout << 1 << " ";
            }else{
                cout << 2<< " ";
            }
        }
        
        cout << endl;
    }
    
}