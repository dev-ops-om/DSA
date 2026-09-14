class Solution {
private:
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Length of valid palindrome is (right - 1) - (left + 1) + 1 = right - left - 1
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0;
        int max_len = 1;

        for (int i = 0; i < s.size(); i++) {
            int len_odd = expand(s, i, i);         // Odd-length center
            int len_even = expand(s, i, i + 1);     // Even-length center
            int curr_max = max(len_odd, len_even);

            if (curr_max > max_len) {
                max_len = curr_max;
                // Calculate starting index from center i and length curr_max
                start = i - (curr_max - 1) / 2;
            }
        }

        return s.substr(start, max_len);
    }
};