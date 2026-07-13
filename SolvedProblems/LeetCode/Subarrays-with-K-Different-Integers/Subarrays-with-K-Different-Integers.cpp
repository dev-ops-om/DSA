class Solution {

    int helper(vector<int>& nums, int k){
        int left=0;
        int n=nums.size();
        int ans=0;
        int count=0;
      vector<int>freq(n+1,0);
     
        for(int right=0;right<n;right++){
freq[nums[right]]++;

     if(freq[nums[right]]==1){
    count++;
          } 

        while(count>k){
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
       count--;
    }
              left++;
        }
      
        ans+=right-left+1;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int x=helper(nums,k);
        int y=helper(nums,k-1);
         return x-y;
    }
};