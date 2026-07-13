class Solution {
  public:
    vector<int> findTwoElement(vector<int>& nums) {
     // Size of the array
        long long n = nums.size(); 

        // Sum of first n natural numbers
              // Expected sums
        long long sumN = n * (n + 1) / 2;
        long long sqSumN = n * (n + 1) * (2 * n + 1) / 6;

        // Actual sums
        long long sum = 0, sqSum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sqSum += (long long)nums[i] * (long long)nums[i];
        }

 //Compute the difference values
  long long diff = sum - sumN;           // X - Y
        long long diffSq = sqSum - sqSumN;     // X^2 - Y^2

        long long sumXY = diffSq / diff;       // X + Y

        int rep = (diff + sumXY) / 2;          // repeating
        int miss = rep - diff;                 // missing

        return {rep, miss};
    }
};