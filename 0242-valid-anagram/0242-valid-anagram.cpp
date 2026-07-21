class Solution {
public:

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

   vector<int>freq(26,0);
    // Count frequency for s
    for (char c : s) {
        freq[c-'a']++;
    }

    // Subtract frequency for t
    for (char c : t) {
        freq[c-'a']--;
        if (freq[c-'a'] < 0) return false; // early exit if mismatch
    }

    return true; // all counts balanced
}
};