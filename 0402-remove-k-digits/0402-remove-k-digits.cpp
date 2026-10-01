class Solution {
public:
    string removeKdigits(string num, int k) {
        // Base case: if we must remove all characters
        if (k >= num.size()) return "0";

        string st = ""; // String used as a monotonic stack

        for (char c : num) {
            // While previous digit is larger and we still have removals left
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // If k > 0, remove remaining digits from the end (the largest ones)
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeroes
        int start = 0;
        while (start < st.size() && st[start] == '0') {
            start++;
        }

        string result = st.substr(start);
        return result.empty() ? "0" : result;
    }
};