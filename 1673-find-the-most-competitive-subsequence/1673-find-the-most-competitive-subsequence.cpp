class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>st;
        int removal=n-k;

        for(int i=0;i<n;i++){
            while(!st.empty() && st.back()>nums[i] && removal>0){
                st.pop_back();
                removal--;
            }
            st.push_back(nums[i]);
        }
        st.resize(k);
        return st;
    }
};