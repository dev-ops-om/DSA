class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int ans=0;
        int n=arr.size();
    int right=n-1;
    int left=0;
    while(left<right){
        int height=min(arr[left],arr[right]);
        int area=height*(right-left);
        ans=max(ans,area);
        
        
        if(arr[left]<arr[right]){
            left++;
        }
        else{
            right--;
        }
        
    }
      return ans;
    }
};