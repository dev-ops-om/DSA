class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=0;
        int n=nums.size();
        int currReach=0;
        for(int i=0;i<n;i++){
            maxReach=max(maxReach,i+nums[i]);
            if(maxReach>=n-1){
                return 1;
            }
            if(i==currReach){
                if(i==maxReach){
                    return 0;
                }
                else{
                    currReach=maxReach;
                }
            }
        }
        return 1;
    }
};