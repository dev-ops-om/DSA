class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
      int currSum=0;
      int maxSum=INT_MIN;
      for(int i=0;i<arr.size();i++){
          currSum=max(arr[i],currSum+arr[i]);
          maxSum=max(maxSum,currSum);
          
      }
      return maxSum;
    }
};