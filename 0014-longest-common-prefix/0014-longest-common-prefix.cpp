class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string firstWord=strs[0];
        for(int i=0;i<firstWord.size();i++){
            char ch=firstWord[i];

            for(int j=1;j<strs.size();j++){
                if(strs[j].size()<i || strs[j][i]!=ch){
                    return strs[j].substr(0,i);
                }
            }
        }
return firstWord;

    }
};