class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        vector<int>lower(26,0);
        vector<int>upper(26,0);
        for(auto &ch:s)
        {
            if(ch>='a'){
                lower[ch-'a']++;
            }else
            {
                upper[ch-'A']++;
            }
        }
        int count=0;
        bool oddFlag=0;
        for(int i=0;i<26;i++){
            if(lower[i]%2==0)
            count+=lower[i];
            else{
                count+=lower[i]-1;
                oddFlag=1;
            }

            if(upper[i]%2==0)
            count+=upper[i];
            else{
                count+=upper[i]-1;
                oddFlag=1;
            }
        }
        if(oddFlag)
        count++;

        return count;
    }
};