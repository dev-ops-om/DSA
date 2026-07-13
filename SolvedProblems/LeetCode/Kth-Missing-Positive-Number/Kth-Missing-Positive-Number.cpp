class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int start=0;
        int ans=arr.size()+k;
        int end=arr.size()-1;
        while(start<=end){
            int mid=(start+end)/2; 
            if(arr[mid]-mid-1>=k){
                ans=mid+k;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }     
        return ans;   
    }
};