class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int ans = nums[0];   // important change
        int max_end_here = nums[0];
        int min_end_here = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] == 0){
                max_end_here = 0;
                min_end_here = 0;
                ans = max(ans, 0);
            }
            else if(nums[i] > 0){
                max_end_here = max(nums[i], nums[i] * max_end_here);
                min_end_here = min(nums[i], nums[i] * min_end_here);
            }
            else{
                int temp = max_end_here;
                max_end_here = max(nums[i], nums[i] * min_end_here);
                min_end_here = min(nums[i], nums[i] * temp);
            }

            ans = max(ans, max_end_here);
        }

        return ans;
    }
};
