class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
 int low=0;
 int n=arr.size();
 int high=arr.size()-1;
 int ans=n+k;
 
 while(low<=high){
     int mid=(high+low)/2;
     
     if(arr[mid]-mid-1>=k){
         ans=mid+k;
          high=mid-1;
     }
     else{
         low=mid+1;
     }
 }
 return ans;

    }
};