class Solution {
public:
    void twopointer(int i, int n, vector<int>& nums, vector<vector<int>>& ans) {
        int left = i+1;
        int right = n;
        int target = 0 - nums[i];  // fixed element

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                ans.push_back({nums[i], nums[left], nums[right]});

                left++;
                right--;

                // skip duplicates for left and right
                while (left < right && nums[left] == nums[left-1]) left++;
                // while (left < right && nums[right] == nums[right+1]) right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-2; i++) {
            // skip duplicates for fixed element
            if (i > 0 && nums[i] == nums[i-1]) continue;

            twopointer(i, n-1, nums, ans);
        }
        return ans;
    }
};