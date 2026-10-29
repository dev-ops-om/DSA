class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=INT_MIN;
        int freq=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==ans){
                freq++;
                ans=nums[i];
            }
            else if(freq==0){
                ans=nums[i];
            }
            else{
                freq--;
            }
        }
        return ans;
    }
};