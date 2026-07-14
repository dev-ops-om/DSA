class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        
        int maxsum=INT_MIN;
        int currentsum=0;
        int minsum=INT_MAX;
        int currentmin=0;
        int totalsum=0;
      for(int i=0;i<arr.size();i++){
          currentsum=max(arr[i],currentsum+arr[i]);
          maxsum=max(currentsum,maxsum);
          
         
          currentmin=min(arr[i],currentmin+arr[i]);
          minsum=min(currentmin,minsum);
           totalsum+=arr[i];
          
      }
      int circularsum=totalsum-minsum;
      
      if(circularsum==0){
          return maxsum;
      }
        return max(maxsum,circularsum);
    }
};