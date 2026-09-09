class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return "";

        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + '$' + rev;
        int n = combined.size();

        vector<int> lps(n, 0);
        int first = 0;
        int second = 1;

        while (second < n) {
            if (combined[first] == combined[second]) {
                first++;
                lps[second] = first;
                second++;
            } else {
                if (first != 0) {
                    first = lps[first - 1];
                } else {
                    lps[second] = 0;
                    second++;
                }
            }
        }

        // lps[n - 1] is the length of the longest palindromic prefix
        int pal_len = lps[n - 1];
        
        // Take remaining suffix that needs to be mirrored
        string subStr = s.substr(pal_len);
        reverse(subStr.begin(), subStr.end());

        return subStr + s;
    }
};