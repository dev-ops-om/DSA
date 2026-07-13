class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>m(k);
        // unordered_map<int,int>m;
        int prefixsum=0;
        int total=0;
        for(int i=0;i<n;i++){
prefixsum+=nums[i];
int rem=prefixsum%k;

if (rem < 0) {
rem += k; // Handle negative numbers in C++
    }
if(rem==0)
total++;



total+=m[rem];
m[rem]++;
        }
        return total;
    }
};