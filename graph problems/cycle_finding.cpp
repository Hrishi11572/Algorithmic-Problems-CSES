// negative cycle finding -- bellman ford 
#include<bits/stdc++.h>
using namespace std; 
#define INF LLONG_MAX
using lli = long long;


struct Edge {
    int a ;
    int b ; 
    lli c ; 
};

signed main(){
    int n , m; 
    cin >> n >> m;

    vector<Edge> edges(m) ; 
    vector<lli> dist(n+1 , 0);  // distance = 0 for all starting nodes ... virtual node made to connect all of them to eliminate disconnected components 
    vector<int>parent(n+1 , -1);
    
    for(int i=0 ; i<m ; i++){
        int a,b;
        lli c; 
        cin >> a >> b >> c ; 
        edges[i].a = a ; 
        edges[i].b = b ;
        edges[i].c = c ;
    }
    
    dist[1]=0;
    int x;
    for(int i=1 ; i<=n; i++){
        x = -1; 
        for(auto e : edges){
            if(dist[e.a] <  INF){
                if (dist[e.b] > dist[e.a] + e.c){
                    dist[e.b] =  dist[e.a] + e.c; 
                    parent[e.b] = e.a;
                    x = e.b;                      
                } 
            }
        }
    }
    
    if(x==-1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl; 
        
        int curr = x; 
        vector<int>path;
        
        for(int i=1 ; i<=n; i++) curr = parent[curr]; 
        
        for(int y = curr ; ; y = parent[y]){
            path.push_back(y); 
            if(y == curr && path.size() > 1) break ;
        }
        
        reverse(path.begin(), path.end());
        
        for(auto u : path){
            cout << u << " ";
        }
        cout << endl; 
    }
}