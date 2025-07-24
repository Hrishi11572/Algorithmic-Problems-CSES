#include<bits/stdc++.h>
using namespace std; 

int n , m;
vector<vector<int>>g ; 
vector<int>vis;
vector<int>ans ; 

void dfs(int node){
    vis[node]=1;
    
    for(auto v : g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

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
    
    int cnt = 0; 
    for(int i=1 ; i<=n; i++){
        if(!vis[i]){
            ans.push_back(i);
            dfs(i);
            cnt+=1;
        }
    }
    cout << cnt-1 << endl ; 
    
    if(cnt-1 != 0){
        int st=0; 
        int k=2;
        int ed=st+k-1;
        int sz = ans.size();
        
        if(sz == 2){
            for(auto c : ans){
                cout << c << " ";
            }
            cout << endl ;
        }else {
            
            while(ed < sz){
                for(int i=st; i<=ed ; i++){
                    cout << ans[i] << ' ';
                }
                
                if(k>1){
                    cout << endl;
                }
                
                st=ed; 
                ed=st+k-1; 
            }
        }
    }
}