class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 > n2) return false;
        
        vector<int> freq_1(26, 0);
        vector<int> freq_2(26, 0);

        // Build frequency for s1
        for (char ch : s1) {
            freq_1[ch - 'a']++;
        }

        int i = 0, j = 0;
        while (j < n2) {
            freq_2[s2[j] - 'a']++;

            // If window size exceeds n1, shrink from left
            if ((j - i + 1) > n1) {
                freq_2[s2[i] - 'a']--;
                i++;
            }

            // If window size matches and frequencies equal → found permutation
            if ((j - i + 1) == n1 && freq_1 == freq_2) {
                return true;
            }

            j++;
        }
        return false;
    }
};
