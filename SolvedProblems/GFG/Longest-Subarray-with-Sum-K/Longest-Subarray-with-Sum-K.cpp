class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
       int n=arr.size();
        unordered_map<int,int>m;
       int sum=0;
       int ans=0;
      
       for(int i=0;i<n;i++){
           sum+=arr[i];
           
           if (sum==k){
               ans =max(ans,i+1);
               
           }
           int val=sum-k;
           if(m.find(val)!=m.end()){
               ans=max(ans,i-m[val]);
           }
           if(m.find(sum)==m.end())
           m[sum]=i;
       }
       return ans;
    }
};