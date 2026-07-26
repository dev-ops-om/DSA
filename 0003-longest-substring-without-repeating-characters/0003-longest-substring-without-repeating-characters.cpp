class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, 0); // Stores frequencies inside current window
        int left = 0;
        int maxlength = 0;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++; // Add s[i] to the window

            // If s[i] is a duplicate, shrink window step-by-step from the left
            while (freq[s[i]] > 1) {
                freq[s[left]]--;
                left++;
            }

            // At this point, the window s[left...i] is guaranteed to be valid
            maxlength = max(maxlength, i - left + 1);
        }

        return maxlength;
    }
};