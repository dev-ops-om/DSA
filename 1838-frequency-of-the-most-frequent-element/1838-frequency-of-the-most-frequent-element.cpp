class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Step 1: Sort the array so that closest elements are adjacent
        sort(nums.begin(), nums.end());

        long long window_sum = 0;
        int left = 0;
        int max_freq = 0;

        // Step 2: Expand the window with pointer 'right'
        for (int right = 0; right < nums.size(); right++) {
            window_sum += nums[right];

            // Step 3: If current window costs more than k, shrink from left
            // Use 1LL to prevent 32-bit integer overflow during multiplication
            while ((1LL * (right - left + 1) * nums[right]) - window_sum > k) {
                window_sum -= nums[left];
                left++;
            }

            // Step 4: Record maximum valid window length
            max_freq = max(max_freq, right - left + 1);
        }

        return max_freq;
    }
};