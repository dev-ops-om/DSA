class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>freq(n+1,0);
        int count=0;
        int total=0;
        int left=0;
        for(int right=0;right<n;right++){
            freq[nums[right]]++;

          if(freq[nums[right]]==1){
    count++;
          }  

          while(count==k){
            total+=(n-right);
            freq[nums[left]]--;

            if(freq[nums[left]]==0){
                count--;
            }
            left++;
          }
        }

         freq.assign(n + 1, 0);
         count=0;
        
        left=0;
        for(int right=0;right<n;right++){
            freq[nums[right]]++;

          if(freq[nums[right]]==1){
    count++;
          }  

          while(count==k+1){
            total-=(n-right);
            freq[nums[left]]--;

            if(freq[nums[left]]==0){
                count--;
            }
            left++;
          }
        }

return total;
    }
};