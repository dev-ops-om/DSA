class Solution {
public:
    string addStrings(string num1, string num2) {
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        string ans;
        int carry = 0;
        int sum;

        // 1) Process both strings while both indices are valid
        while (index1 >= 0 && index2 >= 0) {
            sum   = (num1[index1] - '0') + (num2[index2] - '0') + carry;
            carry = sum / 10;
            ans.push_back('0' + (sum % 10));
            index1--;
            index2--;
        }

        // 2) Process any leftover digits in num1
        while (index1 >= 0) {
            sum   = (num1[index1] - '0') + carry;
            carry = sum / 10;
            ans.push_back('0' + (sum % 10));
            index1--;
        }

        // 3) Process any leftover digits in num2
        while (index2 >= 0) {
            sum   = (num2[index2] - '0') + carry;
            carry = sum / 10;
            ans.push_back('0' + (sum % 10));
            index2--;
        }

        // 4) Final carry
        if (carry) {
            ans.push_back('0' + carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};