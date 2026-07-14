class Solution {
  public:
    int countAtMostK(vector<int> &nums, int k) {
        
          int left=0;
        int n=nums.size();
        int ans=0;
        int count=0;
    unordered_map<int,int>freq;
     
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
        
    
};