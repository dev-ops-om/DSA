class Solution {
    
  static bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
  public:
    int minRemoval(vector<vector<int>> &intervals) {
      sort(intervals.begin(), intervals.end(), compare);
      int count=0;
      int n=intervals.size();
      int end=intervals[0][1];
      for(int i=1;i<n;i++){
          
          
          if(intervals[i][0]<end){
              count++;
              end=min(end,intervals[i][1]);
          }
          else{
              end=intervals[i][1];
          }
      }
        return count;
    }
};
