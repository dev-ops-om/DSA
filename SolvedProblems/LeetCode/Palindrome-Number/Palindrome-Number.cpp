class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return 0;
        int rem;
        int ans = 0;
        int num = x;  //we have created this for keeping orginal value to conpare
        while (num != 0) {
            rem = num% 10;
              if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
               return false;
            }
            ans = ans * 10 + rem;
            num = num / 10;
        }
        if (ans == x) {
            return 1;
        } else {
            return 0;
        }
    }
};