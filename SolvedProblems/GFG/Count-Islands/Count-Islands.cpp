class Solution {
public:
    int r;
    int c;
    int row[8] = {-1,-1,-1,1,1,1,0,0};
    int col[8] = {-1,0,1,-1,0,1,-1,1};

    bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int countIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();

        queue<pair<int,int>> q;
        int count = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 'L') {
                    count++;
                    q.push({i,j});
                    grid[i][j] = 'W';

                    while(!q.empty()) {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();

                        for(int k = 0; k < 8; k++) {
                            int ni = new_i + row[k];
                            int nj = new_j + col[k];
                            if(valid(ni, nj) && grid[ni][nj] == 'L') {
                                grid[ni][nj] = 'W';
                                q.push({ni, nj});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};