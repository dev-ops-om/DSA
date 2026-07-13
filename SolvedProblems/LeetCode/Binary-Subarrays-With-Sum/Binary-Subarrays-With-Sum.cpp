class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
   return helper(nums,goal)-helper(nums,goal+1);
    }
private:
 int helper(vector<int>& nums, int goal){
  
        int start=0;
        int end=0;
        int sum=0;
        int n=nums.size();
        int count=0;

        // if(goal<=0){
        //     return (n*(n+1))/2;
        // }
        while(end<n){
            sum+=nums[end];

            while(sum>=goal && start<=end){
               count+=(n-end);
               sum-=(nums[start]);
               start++;
            }
           
  end++;
        }
        return count;
    }
};