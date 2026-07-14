class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);  // FIXED: initialized with size n
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                int idx = st.top();
                ans[idx] = idx - i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) {
            int idx = st.top();
            ans[idx] = idx + 1;
            st.pop();
        }

        return ans;
    }
};