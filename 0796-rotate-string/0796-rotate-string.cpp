class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        int n = s.size();
        string temp = s;

        for (int i = 0; i < n; i++) {
            if (temp == goal) return true;

            // rotate once
            char first = temp[0];
            temp.erase(temp.begin());
            temp.push_back(first);
        }
        return false;
    }
};
