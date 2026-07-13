class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=INT_MIN;
        int minele=prices[0];
        for(int i=1;i<n;i++){
          minele=min(minele,prices[i]);
          ans=max(ans,prices[i]-minele);
        }
        if(ans<0){
            return 0;
        }
        return ans;
    }
};