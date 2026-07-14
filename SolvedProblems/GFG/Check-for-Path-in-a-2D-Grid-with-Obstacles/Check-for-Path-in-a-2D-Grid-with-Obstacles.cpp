
class Solution {
  public:
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    
    bool valid(int i, int j, int n) {
        return i>=0 && j>=0 && i<n && j<n;
    }
    
    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        int n = grid.size();
        int src_i=-1, src_j=-1;
        int dest_i=-1, dest_j=-1;
        
        // locate source and destination
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    src_i=i; src_j=j;
                }
                if(grid[i][j]==2){
                    dest_i=i; dest_j=j;
                }
            }
        }
        
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        
        q.push({src_i,src_j});
        visited[src_i][src_j] = true;
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if(i==dest_i && j==dest_j) return true;
            
            for(int k=0;k<4;k++){
                int new_i = i + row[k];
                int new_j = j + col[k];
                
                if(valid(new_i,new_j,n) && !visited[new_i][new_j] && (grid[new_i][new_j]==3 || grid[new_i][new_j]==2)){
                    visited[new_i][new_j] = true;
                    q.push({new_i,new_j});
                }
            }
        }
        
        return false;
    }
};