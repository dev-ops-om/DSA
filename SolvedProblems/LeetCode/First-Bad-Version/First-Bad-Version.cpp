// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        // if(n==1){
        //     if(isBadVersion(n)){
        //         return 1;
        //     }
        //     return -1;
        // }
        int left=1;
        int right=n;
        int ans=INT_MAX;
       while(left<=right){
        int mid=left+(right-left)/2;

        if(isBadVersion(mid)){
            ans=min(ans,mid);
            right=mid-1;
        }
        else
        left=mid+1;
       }
       return ans;
    }
};