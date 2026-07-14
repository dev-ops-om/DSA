class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            while (!st.empty() && arr[st.top()] < arr[idx]) {
                ans[st.top()] = arr[idx];
                st.pop();
            }
            // Only push indices from the first pass
            if (i < n) {
                st.push(idx);
            }
        }

        return ans;
    }
};