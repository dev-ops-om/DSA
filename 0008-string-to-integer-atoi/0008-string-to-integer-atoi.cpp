class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int sign=1;
        long ans=0;
int i=0;
        while(i<n &&s[i]==' ')
        i++;

        if(i<n && (s[i]=='+'||s[i]=='-'))
        {
            sign=(s[i]=='-')?-1:1;
            i++;
        }
while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
//we can simply use isdigit 
          
         if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
    return (sign == 1) ? INT_MAX : INT_MIN;
}
            ans = ans * 10 + digit;
            i++;
        }

        return ans * sign;

    }
};