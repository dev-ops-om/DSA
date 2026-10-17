class Solution {
private:
    bool matches(const string& word, const string& pattern) {
        vector<char> p_to_w(128, 0);
        vector<char> w_to_p(128, 0);

        for (int i = 0; i < pattern.size(); i++) {
            char p = pattern[i];
            char w = word[i];

            if (p_to_w[p] != 0 && p_to_w[p] != w) return false;
            if (w_to_p[w] != 0 && w_to_p[w] != p) return false;

            p_to_w[p] = w;
            w_to_p[w] = p;
        }

        return true;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;

        for (const string& w : words) {
            if (matches(w, pattern)) {
                result.push_back(w);
            }
        }

        return result;
    }
};