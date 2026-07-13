class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int start=1;
        int ans=INT_MAX;
        int end=0;
      long long sum=0;
        for(int i=0;i<n;i++){
            end=max(end,piles[i]);
            sum+=piles[i];
        }
start=sum/h;
     if (!start) {
            start = 1;
        }
        while(start<=end){
            int mid=start+(end-start)/2;

long long total_hours=0;
            for(int i=0;i<n;i++){
                total_hours+=(piles[i]+mid-1)/mid;

            }
            if(total_hours<=h){
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