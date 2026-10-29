class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    int n=nums.size();
    vector<int>ans(n,0);

    int pos=0;
    int neg=1;
    int right=0;
    while(right<nums.size() ){
        if(nums[right]>0){
            ans[pos]=nums[right];
            pos+=2;
        }
        else{
            ans[neg]=nums[right];
            neg+=2;
        }

        right++;

    }



return ans;

    }
};