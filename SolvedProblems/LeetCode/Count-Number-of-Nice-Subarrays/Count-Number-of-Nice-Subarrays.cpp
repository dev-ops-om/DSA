class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0;
        int oddCount = 0;
        int prefixEvens = 0;
        int totalSubarrays = 0;

        for (int right = 0; right < nums.size(); right++) {
            // 1. If the current number is odd, increase our odd count
            if (nums[right] % 2 != 0) {
                oddCount++;
                // Crucial: A new odd number means any old left-side even pool 
                // is no longer valid for this new right boundary. Reset it!
                prefixEvens = 0;
            }

            // 2. If we have too many odds, shrink the window from the left
            while (oddCount > k) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }

            // 3. If we have EXACTLY k odds, count how many evens are on the left
            if (oddCount == k) {
                // Shrink the left boundary to count the trailing evens
                while (left < right && nums[left] % 2 == 0) {
                    prefixEvens++;
                    left++;
                }
                
                // Each even number on the left gives us 1 optional starting point.
                // +1 represents the subarray starting exactly at the first odd number.
                totalSubarrays += (prefixEvens + 1);
            }
        }

        return totalSubarrays;
    }
};