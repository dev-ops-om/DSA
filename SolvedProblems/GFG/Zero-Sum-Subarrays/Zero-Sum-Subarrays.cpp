class Solution {
  public:
    int findSubarray(vector<int> &arr) {
  int n=arr.size();
  long long int total=0;
  unordered_map<long long int ,long long int >m;
  long long int prefsum=0;
  
  m[0]=1;
  for(int i=0;i<n;i++){
      prefsum+=arr[i];
      if(m.count(prefsum)){
          total+=m[prefsum];
          m[prefsum]++;
          
      }
      else{
          m[prefsum]=1;
      }
    
  }
    return total;
    }
};