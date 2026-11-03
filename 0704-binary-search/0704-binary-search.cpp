class Solution {
public:

int helper(vector<int>& arr, int target,int start,int end){
    if(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            return helper(arr,target,start,mid-1);
        }
        else{
           return helper(arr,target,mid+1,end);
        }
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        return helper(nums,target,0,n-1);
    }
};