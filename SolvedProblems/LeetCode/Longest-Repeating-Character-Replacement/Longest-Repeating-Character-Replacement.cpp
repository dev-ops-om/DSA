class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int n = s.length();
        int left = 0;
        int max_freq = 0; // Tracks the frequency of the most common character in the window
        int ans = 0;
        
        for (int right = 0; right < n; right++) {
            freq[s[right] - 'A']++;
            
            // Update the highest frequency seen in the current window
            max_freq = max(max_freq, freq[s[right] - 'A']);
            
            // Current window size is (right - left + 1)
            // Characters to replace = window_size - max_freq
            // If this exceeds k, the window is invalid -> shrink from left
            while ((right - left + 1) - max_freq > k) {
                freq[s[left] - 'A']--;
                left++;
                // Note: You don't strictly need to recalculate max_freq here 
                // because a smaller max_freq will never give a larger window answer anyway!
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};