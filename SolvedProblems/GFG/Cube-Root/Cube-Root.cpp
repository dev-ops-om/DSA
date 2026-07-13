class Solution {
  public:
    int cubeRoot(int n) {
    int ans=1;
        if(n<8){
            return 1;
        }
        int low=1;
        int high=n/3;
        while(low<=high){
            long long mid=low+(high -low)/2;
            if(mid*mid==n/mid){
                return mid;
            }
            else if(mid*mid<n/mid){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};