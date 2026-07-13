class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
    //     vector<int>prefixsum(n,0);
    //     prefixsum[0]=nums[0];
    //     for(int i=1;i<n;i++){
    //  prefixsum[i]=prefixsum[i-1]+nums[i];
    //     }

int prefixsum=0;
int count=0;
unordered_map<int,int>m;
        for(int j=0;j<n;j++){
            prefixsum+=nums[j];
            if(prefixsum==k)
            count++;
         
         int val=prefixsum-k;
          if(m.find(val)!=m.end())
         count+= m[val];

         m[prefixsum]++;
        }
        return count;
    }
};