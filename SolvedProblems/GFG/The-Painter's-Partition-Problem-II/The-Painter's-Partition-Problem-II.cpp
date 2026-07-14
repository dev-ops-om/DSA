class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
       int ans=INT_MAX;
       int start=0;
       int n=arr.size();
       int end=0;
            if(arr.size()<k){
            return -1;
        }
       for(int i=0;i<n;i++){
           end+=arr[i];
           start=max(arr[i],start);
       }
        while(start<=end){
            int mid=start+(end-start)/2;
            int temp=0;
                int count=1;
            for(int i=0;i<n;i++){
                temp+=arr[i];
            
                if(temp>mid){
                    count++;
                    temp=arr[i];
                }
            }
            
            if(count<=k){
                ans=min(ans,mid);
                 end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};