class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp1;
unordered_map<string,char> mp2;

int i = 0, j = 0;

while(i < s.size() && j < pattern.size()) {
    int start = i;

    while(i < s.size() && s[i] != ' ')
        i++;

    string word = s.substr(start, i - start);
    char c = pattern[j];

    if(mp1.count(c) && mp1[c] != word) return false;
    if(mp2.count(word) && mp2[word] != c) return false;

    mp1[c] = word;
    mp2[word] = c;

    j++;
    i++; // skip space
}

return (j == pattern.size() && i >= s.size());
    }
};