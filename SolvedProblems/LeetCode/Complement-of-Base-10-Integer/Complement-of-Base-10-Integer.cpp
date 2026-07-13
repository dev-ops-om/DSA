class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1; // special case: 0 → complement is 1
        int mask = 1;
        while(mask <= n) {
            mask = mask << 1;
        }
        mask -= 1; // now mask is all 1s up to MSB
        return mask ^ n;
    }
};