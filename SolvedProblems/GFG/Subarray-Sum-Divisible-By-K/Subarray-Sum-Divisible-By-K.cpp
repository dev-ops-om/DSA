class Solution {
  public:
    // Function to count the number of subarrays with a sum that is divisible by K
    int subCount(vector<int>& arr, int k) {
   int n=arr.size();
    long long total=0;
    long long prefixsum=0;
     unordered_map<long long int,long long int>m;
     for(int i=0;i<n;i++){
         prefixsum+=arr[i];
         int rem=((prefixsum%k)+k)%k;
         
         
         if(rem==0){
             total++;
         }
         total+=m[rem];
         m[rem]++;
         
         
     }
     return total;
    }
};
