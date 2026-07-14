class Solution {
  public:
    int smallestSubWithSum(int target, vector<int>& arr) {
       int sum=0;
       int ans=INT_MAX;
       int start=0;
       for(int end=0;end<arr.size();end++){
           sum+=arr[end];
           
           while(sum>=target && start<arr.size()){
            ans=min(ans,end-start+1);
             sum-=arr[start];
         
            
                   start++;
           }
       }
       
       return (ans==INT_MAX)? 0:ans;
    }
};