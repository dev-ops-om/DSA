class Solution {
  public:
    int countSubarrays(vector<int>& nums, int k) {
       
         int n=nums.size();
          for(int i=0;i<n;i++){
              if(nums[i]%2==0)
              nums[i]=0;
              else
              nums[i]=1;
          }
        vector<int>prefixsum(n,0);
        prefixsum[0]=nums[0];
        for(int i=1;i<n;i++){
     prefixsum[i]=prefixsum[i-1]+nums[i];
        }


int count=0;
unordered_map<int,int>m;
        for(int j=0;j<n;j++){
            if(prefixsum[j]==k)
            count++;
         
         int val=prefixsum[j]-k;
          if(m.find(val)!=m.end())
         count+= m[val];

         m[prefixsum[j]]++;
        }
        return count;
    }
};