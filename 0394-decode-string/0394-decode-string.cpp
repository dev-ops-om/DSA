class Solution {
public:
    string decodeString(string s) {
        stack<int> count_st;
        stack<string> string_st;
        
        string curr_str = "";
        int curr_num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                // Handle multi-digit numbers like "12[ab]"
                curr_num = curr_num * 10 + (c - '0');
            } 
            else if (c == '[') {
                // 1. Push current state
                count_st.push(curr_num);
                string_st.push(curr_str);

                // 2. Reset for the inner scope
                curr_num = 0;
                curr_str = "";
            } 
            else if (c == ']') {
                // 1. Retrieve the count and previous string prefix
                int repeat_count = count_st.top();
                count_st.pop();
                
                string prev_str = string_st.top();
                string_st.pop();

                // 2. Repeat curr_str and attach it to prev_str
                string temp = "";
                while (repeat_count--) {
                    temp += curr_str;
                }
                curr_str = prev_str + temp;
            } 
            else {
                // Normal alphabet character
                curr_str += c;
            }
        }

        return curr_str;
    }
};