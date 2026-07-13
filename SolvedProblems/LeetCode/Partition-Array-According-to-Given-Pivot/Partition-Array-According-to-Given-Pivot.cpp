class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1;

        // First pass: fill < pivot from the left
        for (int x : nums) {
            if (x < pivot) result[left++] = x;
        }

        // Second pass: fill > pivot from the right
        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] > pivot) result[right--] = nums[j];
        }

        // Fill the middle with pivots
        while (left <= right) {
            result[left++] = pivot;
        }

        return result;
    }
};