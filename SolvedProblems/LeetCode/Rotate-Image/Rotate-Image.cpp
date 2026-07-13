class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int j,i,n=matrix.size();
        // transpose code
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
            
        // reverse each row
        for(i=0;i<n;i++){
            // row reverse mat[i]
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
