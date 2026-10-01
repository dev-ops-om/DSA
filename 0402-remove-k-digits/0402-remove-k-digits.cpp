class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size())
        return "0";

        string st="";
        for(char c:num){
    while(!st.empty() && k>0 &&st.back()>c){
        st.pop_back();
        k--;
    }
    st.push_back(c);
        }

        while(k>0 && !st.empty()){
            st.pop_back();
            k--;
        }
        int start=0;
        while(start<st.size() && st[start]=='0' ){
            start++;
        }

        string result=st.substr(start);
        return result.empty() ? "0":result;
    }
};