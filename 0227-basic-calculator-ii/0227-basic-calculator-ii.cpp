class Solution {
public:
    int calculate(string s) {
        int totalResult=0;
        int currentTerm=0;
        int currNum=0;
        char prevOperator='+';

        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(isdigit(c)){
                currNum=currNum*10+(c-'0');
            }

            if((!isdigit(c) && c!=' ')|| i==s.size()-1){
                if(prevOperator=='+'){
                    totalResult+=currentTerm;
                    currentTerm=currNum;
                }
                else if(prevOperator=='-'){
                    totalResult+=currentTerm;
                    currentTerm=-currNum;
                }
                else if(prevOperator == '*') {
                    currentTerm = currentTerm * currNum;

                }
                else if(prevOperator=='/'){
                    currentTerm=currentTerm/currNum;
                }
                prevOperator=c;
                currNum=0;
            }
        }
        totalResult += currentTerm;
        return totalResult;
    }
};