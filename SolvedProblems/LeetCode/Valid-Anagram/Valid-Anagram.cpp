class Solution {
public:

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, int> freq;

    // Count frequency for s
    for (char c : s) {
        freq[c]++;
    }

    // Subtract frequency for t
    for (char c : t) {
        freq[c]--;
        if (freq[c] < 0) return false; // early exit if mismatch
    }

    return true; // all counts balanced
}
};