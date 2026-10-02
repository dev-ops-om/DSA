class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> st;

        for (int i = 0; i < n; i++) {
            // Pop as long as:
            // 1. Stack is not empty
            // 2. Incoming number is smaller than the top
            // 3. Popping still leaves enough elements to reach size k
            while (!st.empty() && st.back() > nums[i] && (st.size() - 1 + n - i >= k)) {
                st.pop_back();
            }

           
          
                st.push_back(nums[i]);
            
        }
        st.resize(k);
        return st;

        return st;
    }
};