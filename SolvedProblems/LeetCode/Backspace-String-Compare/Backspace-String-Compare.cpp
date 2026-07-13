class Solution {
public:
    string removeConsecutiveSame(vector<char>& arr) {
        stack<char> s;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != '#') {
                s.push(arr[i]);
            } else {
                if (!s.empty())
                    s.pop();
            }
        }

        string result = "";
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool backspaceCompare(string s, string t) {
        vector<char> a(s.begin(), s.end());
        vector<char> b(t.begin(), t.end());

        return removeConsecutiveSame(a) == removeConsecutiveSame(b);
    }
};