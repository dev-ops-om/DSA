class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
    int n=nums.size();
    int end=n-1;
    while(start<=end){
        int mid=end+(start-end)/2;
        if(nums[mid]==target){
            return mid;
        }   // right hand sorted
        else if(nums[mid]<=nums[0]){
              if(nums[mid]<=target && nums[end]>=target){
                start=mid+1;
              } 
              else{
               end=mid-1;
              }
        }  //left hand sorted
        else{ 
            if(nums[start]<=target&& nums[mid]>=target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
    }
    return -1;
    }
};