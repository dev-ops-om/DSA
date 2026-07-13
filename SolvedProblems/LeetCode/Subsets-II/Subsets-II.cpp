class Solution {
public:
void ps(vector<int>& nums,int i,vector<vector<int>> &ans,vector<int>&temp){

     if(i==nums.size()){
        ans.push_back(temp);
        return;
     }
     temp.push_back(nums[i]);
      ps(nums,i+1,ans,temp);
  int index=i+1;

temp.pop_back();
      while(index<nums.size()&& nums[index]==nums[index-1]){
        index++;
      }
       ps(nums,index,ans,temp);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        int n=nums.size();
        int i=0;
        sort(nums.begin(),nums.end());
        ps(nums,i,ans,temp);
        return ans;

    }
};