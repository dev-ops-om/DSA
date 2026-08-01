class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 > n2) return false;
        
        // Sort s1 once
        string sorted_s1 = s1;
        sort(sorted_s1.begin(), sorted_s1.end());
        
        // Slide a window of size n1 across s2
        for (int i = 0; i <= n2 - n1; i++) {
            // Extract substring of length n1
            string sub = s2.substr(i, n1);
            
            // Sort the substring
            sort(sub.begin(), sub.end());
            
            // If sorted substring matches sorted s1, a permutation exists!
            if (sub == sorted_s1) {
                return true;
            }
        }
        
        return false;
    }
};