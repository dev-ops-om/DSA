class Solution {
  public:
    bool isRotated(string& s1, string& s2) {
        int n = s1.size();
        if (n != s2.size()) return false;

        string anticlock(n, ' '), clock(n, ' ');

        // Build rotated strings using modular indexing
        for (int i = 0; i < n; i++) {
            // Anti-clockwise rotation by 2 (left shift)
            anticlock[(i - 2 + n) % n] = s1[i];

            // Clockwise rotation by 2 (right shift)
            clock[(i + 2) % n] = s1[i];
        }

        return (s2 == anticlock || s2 == clock);
    }
};