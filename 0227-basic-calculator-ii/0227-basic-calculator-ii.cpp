class Solution {
public:
    int calculate(string s) {
stack<int>st;
int  currNumber=0;
char prevOperator='+';

for(int i=0;i<s.size();i++){
    char c=s[i];
    if(isdigit(c)){
        currNumber=currNumber*10+(c-'0');
    }

    if((!isdigit(c) && c!=' ' && c!=0) || i==s.size()-1 ){
        if (prevOperator == '+') {
                    st.push(currNumber);
                } 
                else if (prevOperator == '-') {
                    st.push(-currNumber);
                } 
                else if (prevOperator == '*') {
                    int topVal = st.top();
                    st.pop();
                    st.push(topVal * currNumber);
                } 
                else if (prevOperator == '/') {
                    int topVal = st.top();
                    st.pop();
                    st.push(topVal / currNumber);
                }

                prevOperator=c;
                currNumber=0;
    }
}
int totalResult = 0;
        while (!st.empty()) {
            totalResult += st.top();
            st.pop();
        }

        return totalResult;
    }
};