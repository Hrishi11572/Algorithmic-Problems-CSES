#include<bits/stdc++.h>
using namespace std; 

int n,m ; 
vector<vector<char>> grid;
vector<vector<int>>vis;

int dx[4] = {1,-1,0,0}; 
int dy[4] = {0,0,1,-1}; 

void dfs(int i , int j){
    vis[i][j] = 1; 
    
    for(int k=0 ; k<4 ; k++){
        int x = i + dx[k]; 
        int y = j + dy[k]; 
        
        if(x >=0 and x < n and y>=0 and y<m and !vis[x][y] and grid[x][y] == '.'){
            dfs(x , y);
        }
    }
}

int main(){
    cin >> n >> m;
    
    vis.assign(n , vector<int>(m , 0)); 
    grid.assign(n , vector<char>(m)); 
    
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> grid[i][j]; 
        }
    }
    
    // for(int i=0 ; i<n ; i++){
    //     for(int j=0 ; j<4 ; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl ; 
    // }
    
    int cnt=0; 
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j]=='.' and !vis[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }   
    
    cout << cnt << endl ; 
}