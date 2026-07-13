class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
     //step1
     int n=mat.size();
     for(int j=0;j<n;j++){
         int start=0;
         int end=n-1;
         while(start<end){
         swap(mat[start][j],mat[end][j]);
         start++;
         end--;
         }
     }
     //step2;
     for(int i=0;i<n;i++){
        int start=0;
        int end=n-1;
         while(start<end){
             swap(mat[i][start],mat[i][end]);
             start++;
             end--;
         }
     }
    }
};