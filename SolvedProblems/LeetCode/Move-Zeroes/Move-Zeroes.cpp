class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastnonzerofound=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[lastnonzerofound]=nums[i];
                lastnonzerofound++;
            }
        }
        for(int i=lastnonzerofound;i<nums.size();i++){
            nums[i]=0;
        }
    }
};