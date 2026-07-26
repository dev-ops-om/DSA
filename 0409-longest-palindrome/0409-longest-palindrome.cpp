class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0); // covers both upper and lower case
        int oddFreq = 0;
        int n = s.length();

        for (char ch : s) {
            freq[ch]++;
            if (freq[ch] % 2 == 1) {
                oddFreq++;
            } else {
                oddFreq--;
            }
        }

        if (oddFreq > 0) {
            return n - oddFreq + 1;
        }
        return n;
    }
};
