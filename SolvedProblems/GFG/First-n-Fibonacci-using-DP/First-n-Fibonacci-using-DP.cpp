class Solution {
  public:
    vector<int> Series(int n) {
        const int MOD = 1e9 + 7;
        vector<int> ans;
        
        long long a = 0, b = 1;
        for (int i = 0; i <= n; i++) {
            ans.push_back(a % MOD);  // store current term
            long long next = (a + b) % MOD;
            a = b;
            b = next;
        }
        
        return ans;
    }
};
