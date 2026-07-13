class Solution {
public:
    void sortColors(vector<int>& nums) {
        // dutch national flag algorithm
    int n=nums.size();
    int mid=0;
    int high=n-1,low=0;
    while(mid<=high){
      if(nums[mid]==0){
        swap(nums[mid],nums[low]);
        low++;
        mid++;
      }
      else if(nums[mid]==1){
        mid++;
      }
      else{
        swap(nums[mid],nums[high]);
        high--;
      }
    }

    }
};