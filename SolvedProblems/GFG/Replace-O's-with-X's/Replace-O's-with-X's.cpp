class Solution {
  public:
      int r;
    int c;
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    void fill(vector<vector<char>>& grid) {
         r = grid.size();
        c = grid[0].size();
        
         queue<pair<int,int>> q;
         for(int j=0;j<c;j++){
             if(grid[0][j]=='O'){
                 q.push(make_pair(0,j));
                 grid[0][j]='T';
             }
         }
          for(int j=1;j<r;j++){
             if(grid[j][0]=='O'){
                 q.push(make_pair(j,0));
                 grid[j][0]='T';
             }
         }
         for(int j=1;j<c;j++){
             if(grid[r-1][j]=='O'){
                 q.push(make_pair(r-1,j));
                 grid[r-1][j]='T';
             }
         }
         for(int j=1;j<r-1;j++){
             if(grid[j][c-1]=='O'){
                 q.push(make_pair(j,c-1));
                 grid[j][c-1]='T';
             }
         }
         
           while(!q.empty()) {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int ni = new_i + row[k];
                            int nj = new_j + col[k];
                            if(valid(ni, nj) && grid[ni][nj] == 'O') {
                                grid[ni][nj] = 'T';
                                q.push({ni, nj});
                            }
                        }
}
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        if(grid[i][j]=='O')
        grid[i][j]='X';
        
        else if(grid[i][j]=='T')
        grid[i][j]='O';
        
        
    }
}

        
    }
};