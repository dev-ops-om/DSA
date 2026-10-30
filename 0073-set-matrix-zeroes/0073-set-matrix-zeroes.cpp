class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix[0].size();
        int n=matrix.size();
bool col0=0;
        for(int i=0;i<n;i++){
            
            if(matrix[i][0]==0){
                col0=1;
            }
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int c = 0; c < m; c++) {
                matrix[0][c] = 0;
            }
        }

        if (col0) {
            for (int r = 0; r < n; r++) {
                matrix[r][0] = 0;
            }
        }

    }
};