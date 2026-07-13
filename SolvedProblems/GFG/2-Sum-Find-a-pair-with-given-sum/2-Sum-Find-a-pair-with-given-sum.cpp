class Solution {
  public:
    vector<int> twoSum(vector<int> &arr, int target) {
     unordered_map<int,int>m;
     for(int i=0;i<arr.size();i++){
         int val=target-arr[i];
         
         if(m.find(val)!=m.end()){
             return {val,arr[i]};
         }
         m[arr[i]]=i;
     }
     return {};
        
    }
};