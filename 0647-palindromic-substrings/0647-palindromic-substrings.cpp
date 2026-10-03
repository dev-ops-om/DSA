class Solution {
private:
    int expandAroundCenter(const string& s, int left, int right) {
        int count = 0;
        // Expand outward as long as pointers stay in bounds and characters match
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;   // Found a valid palindromic substring
            left--;    // Move left pointer outward
            right++;   // Move right pointer outward
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int total_palindromes = 0;

        for (int i = 0; i < s.size(); i++) {
            // Case 1: Odd-length palindromes (single-character center)
            total_palindromes += expandAroundCenter(s, i, i);

            // Case 2: Even-length palindromes (two-character center)
            total_palindromes += expandAroundCenter(s, i, i + 1);
        }

        return total_palindromes;
    }
};