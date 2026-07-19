class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int i = n - 1;
        while (i >= 0) {
            if (num[i] % 2 == 0) {
                i--;
            }
            else {
                break;
            }
        }
        // FIX 2: If i broke out and is less than 0, it means NO odd digit was found anywhere
        if (i < 0)
            return "";
            
        // FIX 1: Change length from 'i' to 'i + 1' to include the odd digit itself
        return num.substr(0, i + 1);
    }
};