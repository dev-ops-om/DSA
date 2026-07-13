class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n,0);
       vector<int>ans(n,0);

        for(int i=0;i<bookings.size();i++){
            int start=bookings[i][0];
            int end=bookings[i][1];
            int seats=bookings[i][2];

        diff[start-1]+=seats;//0 based index
        if(end<n){
            diff[end]-=seats;
        }
        }
        ans[0]=diff[0];
        for(int i=1;i<n;i++){
            ans[i]=diff[i]+ans[i-1];
        }
        return ans;
    }
};