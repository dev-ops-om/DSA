class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int i=0;
        int n=interval.size();

        //pushing lesser element
        while(i<n &&newInterval[0]> interval[i][1]){
            ans.push_back(interval[i]);
            i++;

        }
        while(i<n && interval[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],interval[i][0]);
               newInterval[1]=max(newInterval[1],interval[i][1]);
 i++;
        }
        ans.push_back(newInterval);

        while(i<n){
            ans.push_back(interval[i]);
            i++;
        }
        return ans;
    }
};