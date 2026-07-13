class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        

        int n=arr.size();
        int left=0;
        int ans=n+1;
  int sum=0;
        for(int right=0;right<n;right++){
            sum+=arr[right];
            while(sum>=target){
                ans=min(ans,right-left+1);
                sum-=arr[left++];
                
            }

        }
        return ans==n+1 ? 0 :ans;
    }
};