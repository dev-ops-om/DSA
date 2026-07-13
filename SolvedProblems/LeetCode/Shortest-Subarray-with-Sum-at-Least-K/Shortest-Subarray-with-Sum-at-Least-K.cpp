class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long ,long long>>dq;
        int n=nums.size();
        long long sum=0;
    long long ans=n+1;
        for(long long i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=k){
                ans=min(ans,i+1);
            }
            while(!dq.empty() && sum-dq.front().first>=k){
              ans = min(ans, i - dq.front().second);
                dq.pop_front();
            }

            while(!dq.empty() && dq.back().first>=sum){
                dq.pop_back();
            }
            dq.push_back({ sum,i});
        }

        return ans==n+1 ? -1: ans;
    }
};