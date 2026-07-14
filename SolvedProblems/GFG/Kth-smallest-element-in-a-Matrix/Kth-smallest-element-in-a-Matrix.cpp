class Solution {
  public:
  
    int countElement(int mid, vector<vector<int>>& mat, int n){
        int cnt = 0;
        int row = n - 1, col = 0;
        while(row >= 0 && col < n){
            if(mat[row][col] <= mid){ //last element of this column
                cnt += row + 1; // all elements in this column till this row
                col++;
            }
            else row--;
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        int i = mat[0][0], j = mat[n - 1][n - 1];
        int ans = -1;
        
        while(i <= j){
            int mid = i + (j - i) / 2;
            int cnt = countElement(mid, mat, n);
            if(cnt >= k){
                ans = mid; //mid could be an ans
                j = mid - 1; //check if smaller ans than mid exist 
            }
            else i = mid + 1;
        }
        return ans;
    }
};
//TC = n * log(max value - min value), SC = 1