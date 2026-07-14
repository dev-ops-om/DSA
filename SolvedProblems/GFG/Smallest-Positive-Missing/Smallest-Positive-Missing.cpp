class Solution {
  public:
    int missingNumber(vector<int> &nums) {
          int n=nums.size();
        vector<bool>temp(n+1,false);
        for(int i=0;i<n;i++){
            if(nums[i]>0&&nums[i]<=n){
   temp[nums[i]]=true;

            }

        }
for(int i=1;i<temp.size();i++){
    if(temp[i]==false){
        return i;
    }
    
}
return n+1;
        
    }
};