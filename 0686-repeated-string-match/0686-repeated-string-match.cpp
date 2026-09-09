class Solution {
private:
    vector<int> buildLPS(const string& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    bool kmpSearch(const string& txt, const string& pat, const vector<int>& lps) {
        int n = txt.size(), m = pat.size();
        int i = 0, j = 0;

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
                if (j == m) return true; // Found pattern
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

public:
    int repeatedStringMatch(string a, string b) {
        vector<int> lps = buildLPS(b);

        string repeated = "";
        int count = 0;

        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        if (kmpSearch(repeated, b, lps)) return count;

        repeated += a;
        count++;
        if (kmpSearch(repeated, b, lps)) return count;

        return -1;
    }
};