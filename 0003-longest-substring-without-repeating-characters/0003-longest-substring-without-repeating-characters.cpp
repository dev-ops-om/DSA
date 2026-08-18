class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
    
        int maxlen=0;

        vector<int>count(256,-1);

for(int i=0;i<s.size();i++){
    
    if(count[s[i]]!=-1 && count[s[i]]>=left){
        left=count[s[i]]+1;
    }
    count[s[i]]=i;
    maxlen=max(maxlen,i-left+1);
}
return maxlen;
    }
};