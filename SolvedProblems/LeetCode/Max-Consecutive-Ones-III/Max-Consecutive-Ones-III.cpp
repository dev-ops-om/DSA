class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right=0;
        int ans=0;
        int left=0;
        int zerocount=0;
        while(right<nums.size()){
            if(nums[right]==0){
                zerocount++;
            }
            while(zerocount>k){
                if(nums[left]==0){
                    zerocount--;
                }
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};