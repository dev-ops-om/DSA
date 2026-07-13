class Solution {
public:
    int val(char c) {
        if (c == 'I')
            return 1;
        else if (c == 'V')
            return 5;
        else if (c == 'X')
            return 10;
        else if (c == 'L')
            return 50;
        else if (c == 'C')
            return 100;
        else if (c == 'D')
            return 500;
        else
            return 1000;
    }
    int romanToInt(string s) {
        int sum=0,index=0;
        while(index<s.size()-1){
            if(val(s[index])<val(s[index+1]))
            sum-=val(s[index]);
            else
            sum+=val(s[index]);
            index++;
        }
        sum+=val(s[s.size()-1]);
        return sum;
    }
};