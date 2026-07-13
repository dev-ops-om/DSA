class Solution {
  public:
    int splitArray(vector<int>& arr, int k) {
        int start=0;
        int end=0;
        for(int i=0;i<arr.size();i++){
            start=max(start,arr[i]);
            end+=arr[i];
        }
    
     //int end=arr.size()-1;
     int ans=INT_MAX;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            int sum=0;
            int count=1;
            for(int i=0;i<arr.size();i++){
                sum+=arr[i];
                if(sum>mid){
                    count++;
                    sum=arr[i];
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