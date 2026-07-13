class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int left = (n - 1) / 2; // middle
        int right = n - 1;      // end

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = sorted[left--];   // smaller half
            } else {
                nums[i] = sorted[right--];  // larger half
            }
        }
    }
};