class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
int start=0; 
int n=nums.size();
int index=n;
int end=n-1; 
while(end>=start){
    int mid=(start+end)/2;
    if(nums[mid]==target){
      index=mid;
      break;
    }
    else if(nums[mid]<target){
        start=mid+1;
    }
    else{
        index=mid;
        end=mid-1;
    }
    }
    return index;
    }
};