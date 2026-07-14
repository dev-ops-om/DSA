class Solution {
public:
    void permut(string &s, vector<string> &ans, int index, string &temp) {
        if (index == s.length()) {
            ans.push_back(temp);
            return;
        }

        vector<bool> visited(26, 0);  // for characters A–Z (assuming uppercase)
        for (int i = index; i < s.length(); i++) {
            if (visited[s[i] - 'A'] == 0) {  // check if this char used at this level
                visited[s[i] - 'A'] = 1;

                // choose
                temp.push_back(s[i]);
                swap(s[i], s[index]);  // place current char at correct position

                // explore
                permut(s, ans, index + 1, temp);

                // unchoose (backtrack)
                swap(s[i], s[index]);
                temp.pop_back();
            }
        }
    }

    vector<string> findPermutation(string &s) {
        vector<string> ans;
        string temp = "";
        permut(s, ans, 0, temp);
        return ans;
    }
};
