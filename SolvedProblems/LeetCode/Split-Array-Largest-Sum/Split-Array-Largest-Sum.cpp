class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
        int start=0;
        int end=0;
        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            start=max(start,arr[i]);
            end+=arr[i];
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