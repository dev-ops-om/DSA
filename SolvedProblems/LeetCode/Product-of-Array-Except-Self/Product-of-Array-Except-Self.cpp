class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
int n=nums.size();
        vector<int>result(n,1);

        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            result[i] = leftProduct;      // Store product of all elements to the left of i
            leftProduct *= nums[i];        // Update left product for next iteration
        }

      int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProduct;     // Multiply with product of all elements to the right of i
            rightProduct *= nums[i];       // Update right product for next iteration
        }
        return result;
    }
};