class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        vector<vector<int>>ans;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
          int  lastend=ans.back()[1];
            
            int start=arr[i][0];
            int end=arr[i][1];
            if(start<=lastend){
                ans.back()[1]=max(lastend,end);
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};