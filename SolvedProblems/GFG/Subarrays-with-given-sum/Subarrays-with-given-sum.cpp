class Solution {
  public:
    int subArraySum(vector<int>& arr, int k) {
    int n=arr.size();
      vector<int>prefixsum(n,0);
      prefixsum[0]=arr[0];
      for(int i=1;i<n;i++){
          prefixsum[i]=prefixsum[i-1]+arr[i];
      }
      unordered_map<int,int>m;
      int count=0;
      for(int j=0;j<n;j++){
          int val=prefixsum[j]-k;
          if(prefixsum[j]==k)
          count++;
          
          if(m.find(val)!=m.end()){
              count+=m[val];
          }
          m[prefixsum[j]]++;
          
      }
      return count;
    }
};