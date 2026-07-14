class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
       int left =0;
       int ans=INT_MIN;
       int count=0;
       for(int right=0;right<arr.size();right++){
           if(arr[right]==0)
           count++;
      
           while(count>k){
             
               if(arr[left]==0)
               count--;
                 left++;
          }
        //   if(count<=k){
              ans=max(ans,right-left+1);
        //   }
           
       }
        return ans;
    }
};
