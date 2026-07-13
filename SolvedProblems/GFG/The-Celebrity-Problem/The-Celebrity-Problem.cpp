class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        stack<int> st;
        int n = mat.size();

        // Push all people into the stack
        for (int i = n - 1; i >= 0; i--) {
            st.push(i);
        }

        int first, second;

        // Compare pairs inside the loop
        while (st.size() > 1) {
            first = st.top(); st.pop();
            second = st.top(); st.pop();

            // preserve your original logic with only necessary change
            if (mat[first][second]) {
                st.push(second);
            } else {
                st.push(first);
            }
        }

        if (st.empty()) return -1;

        int num = st.top(); st.pop();

        int row = 0, col = 0;
        for (int i = 0; i < n; i++) {
            if (i == num) continue;        // <-- SKIP self
            row += mat[num][i];
            col += mat[i][num];
        }

        return row == 0 && col == n - 1 ? num : -1;
    }
};
