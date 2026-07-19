class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string firstWord=strs[0];
       for(int i=0;i<firstWord.size();i++){
        char ch=firstWord[i];

        for(int j=1;j<strs.size();j++){
            if(strs[j].length()<=i || strs[j][i]!=ch )
            return firstWord.substr(0,i);
        }

       }
       return firstWord;

    }
};