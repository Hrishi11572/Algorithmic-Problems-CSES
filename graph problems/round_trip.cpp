#include<bits/stdc++.h>
using namespace std; 

int n , m;
vector<vector<int>>g ; 
vector<int>vis, parent , any_cycle;
bool cycle_found = false;
bool first_ = false;

void dfs(int node, int par){
    vis[node] = 1; // gray 
    parent[node] = par; 
    
    for(auto v: g[node]){
        if(vis[v] == 0 and parent[node] != v){
            dfs(v , node);
        }else if(vis[v] == 1 and parent[node] != v){
            cycle_found = true; 
            if(first_ == false){
                
                first_ = true;
                any_cycle.push_back(v);
                int temp = node; 
                while(temp != v){
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }

                any_cycle.push_back(v);
                reverse(any_cycle.begin() , any_cycle.end());
            }
        }
    }
    
    vis[node] = 2 ; // black 
}

signed main(){
    
    cin >> n >> m ; 
    g.resize(n+1);
    vis.assign(n+1,0);
    parent.assign(n+1, 0);
    
    for(int i=0; i<m ; i++){
        int a , b;
        cin >> a >> b; 
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for(int i=1; i<=n;i++){
        if(vis[i]==0){
            dfs(i,0);
        }
    }
    
    if(cycle_found){
        // length of the cycle and print the cycle 

        cout << any_cycle.size() << endl; 
        for(auto v : any_cycle){
            cout << v << ' ';
        }
        
    }else{
        cout << "IMPOSSIBLE" << endl ; 
    }
}