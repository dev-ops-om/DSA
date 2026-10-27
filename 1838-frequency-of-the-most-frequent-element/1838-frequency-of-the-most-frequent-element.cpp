class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

int left=0;
long long window_sum=0;
int ans=0;
for(int right=0;right<nums.size();right++){
    window_sum+=nums[right];

while(((long long)(right-left+1)*nums[right]-window_sum)>k){
    window_sum-=nums[left];
    left++;
}

ans=max(ans,right-left+1);

}
return ans;

    }
};