class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Stack stores pairs of: {character, consecutive_count}
        vector<pair<char, int>> st;

        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                st.back().second++;
                if (st.back().second == k) {
                    st.pop_back(); // Remove all k duplicates at once
                }
            } else {
                st.push_back({c, 1});
            }
        }

        // Reconstruct the remaining string
        string result = "";
        for (const auto& entry : st) {
            result.append(entry.second, entry.first);
        }

        return result;
    }
};