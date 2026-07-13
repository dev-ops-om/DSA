class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
      int left = 0;
        int right = nums.size() - 1;
        vector<int> ans;
sort(nums.begin(),nums.end());
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            } else if (sum < target) {
                left++;
            } else {
                right--;  
            }
        }
        return {};
    }
};