class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(128,-1);
int left=0;
int maxlength=0;
        for(int i=0;i<s.length();i++){
            if(freq[s[i]]!=-1){
            if(freq[s[i]]>=left){
                left=freq[s[i]]+1;
            }
            }
            maxlength=max(maxlength,i-left+1);
            freq[s[i]]=i;
        }
        return maxlength;
    }
};