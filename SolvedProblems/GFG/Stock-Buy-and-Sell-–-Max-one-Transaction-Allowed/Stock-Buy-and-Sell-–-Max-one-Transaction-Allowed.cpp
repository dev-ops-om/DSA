class Solution {
  public:
    int maxProfit(vector<int> &arr) {
       int ans=0;
       int minele=arr[0];
       for(int i=0;i<arr.size();i++){
           minele=min(arr[i],minele);
           ans=max(ans,arr[i]-minele);
       }
        return ans;
    }
};
