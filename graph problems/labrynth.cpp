#include<bits/stdc++.h>
using namespace std; 

int dx[4] = {1,-1,0,0}; 
int dy[4] = {0,0,1,-1}; 
char dir[4] = {'D', 'U', 'R', 'L'};

int main(){
    int n,m ; 
    cin >> n >> m;
    
    vector<vector<char>> grid;
    vector<vector<int>>vis;
    vector<vector<int>>dist; 
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> move(n , vector<char>(m , '?'));
    
     vis.assign(n , vector<int>(m , 0)); 
    grid.assign(n , vector<char>(m)); 
    dist.assign(n , vector<int>(m, 1e9));
    
    pair<int,int> A, B; 
    
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> grid[i][j]; 
            if(grid[i][j] == 'A'){
                A = {i,j};
            } 
            if(grid[i][j] == 'B'){
                B = {i,j};
            }
        }
    }

    queue<pair<int,int>>q ; 
    q.push(A);
    dist[A.first][A.second] = 0; 
    
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        
        if(vis[node.first][node.second]) continue ; 
        vis[node.first][node.second]=1; 
        
        for(int k=0; k<4; k++){
            int x = node.first + dx[k];
            int y = node.second + dy[k];
            
                if(x >=0 and x< n and y>=0 and y<m){
                    if(grid[x][y] != '#' and dist[x][y] > dist[node.first][node.second]+1){
                        dist[x][y] = dist[node.first][node.second] + 1; 
                        parent[x][y] = {node.first , node.second};
                        move[x][y] = dir[k]; 
                        q.push({x,y});
                    }
                }
        }
        
    }
    
    if(dist[B.first][B.second] != 1e9){
        cout << "YES" << endl;
        cout << dist[B.first][B.second] << endl ; 
        
        // trick 
        string path = "";
        pair<int,int> cur = B;
        
        while(cur != A){
            path += move[cur.first][cur.second];
            cur = parent[cur.first][cur.second];
        }
        
        reverse(path.begin(), path.end());
        cout << path << endl ; 
        
    }else{
        cout << "NO" << endl ; 
    }
        
}