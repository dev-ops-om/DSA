class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        int n = (int)q.size();
        if (n == 0 || k <= 0) return q;

        // Clamp k to size
        if (k > n) return q;

        stack<int> st;

        // Move first k elements to stack
        for (int i = 0; i < k; i++) {
            st.push(q.front());
            q.pop();
        }

        // Push them back reversed
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Rotate remaining n - k elements to back
        for (int i = 0; i < n - k; i++) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};
