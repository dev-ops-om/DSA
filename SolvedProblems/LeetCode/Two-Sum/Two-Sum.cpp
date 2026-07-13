class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
unordered_map<int,int>m;
   int n=arr.size();

   for(int i=0;i<n;i++){
    int x=target-arr[i];
 if(m.find(x)!=m.end()){
    return { i,m[x]};
 }
 m[arr[i]]=i;

   }
   return { };
    }
};