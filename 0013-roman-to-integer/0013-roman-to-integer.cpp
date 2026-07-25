class Solution {
public:
    int romanToInt(string s) {
        // Map allows char -> int lookup directly via p['I']
        unordered_map<char, int> p = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int sum = 0;
        int n = s.size();

        for (int i = 0; i < n - 1; i++) {
            int value = p[s[i]];
            
            // FIX: Changed '>' to '>=' so equal adjacent symbols (like 'III') add up
            if (value >= p[s[i + 1]]) {
                sum += value;
            } else {
                sum -= value;
            }
        }

        // Add the very last character
        sum += p[s[n - 1]];

        return sum;
    }
};