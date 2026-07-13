class Solution {
public:
    int shipWithinDays(vector<int>& arr, int k) {
                int start=0,end=0;
        int ans=INT_MAX;
        
        if(arr.size()<k){
            return -1;
        }
      for(int i=0;i<arr.size();i++)
        {
            start=max(start,arr[i]);
            end+=arr[i];
        }
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            int pages=0;
            int count=1;
        for(int i=0;i<arr.size();i++){
            pages+=arr[i];
            if(pages>mid){
                count++;
                pages=arr[i];
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