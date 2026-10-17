class Solution {
private:
    vector<int> normalize(const string& s) {
        unordered_map<char, int> seen;
        vector<int> signature;
        int next_id = 0;

        for (char c : s) {
            if (!seen.count(c)) {
                seen[c] = next_id++;
            }
            signature.push_back(seen[c]);
        }

        return signature;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> pattern_signature = normalize(pattern);
        vector<string> result;

        for (const string& w : words) {
            if (normalize(w) == pattern_signature) {
                result.push_back(w);
            }
        }

        return result;
    }
};