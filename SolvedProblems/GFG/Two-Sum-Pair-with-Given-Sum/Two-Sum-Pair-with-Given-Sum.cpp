class Solution {
    
    bool binarysearch(vector<int>&arr,int start,int end,int target){
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]<target){
             start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
  public:
    bool twoSum(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
int n=arr.size();
 for(int i=0;i<n;i++){
     int target2=target-arr[i];
     if( binarysearch(arr,i+1,n-1,target2)){
         return true;
     };
 }
 return false;
        
    }
};