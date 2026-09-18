class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
    
        int maxlen=0;
int ans=0;
        vector<int>count(256,-1);

for(int right=0;right<s.size();right++){
  if(count[s[right]]!= -1 && count[s[right]]>=left){
  left=count[s[right]]+1;

  }
  count[s[right]]=right;
  maxlen=max(maxlen,right-left+1);


}
return maxlen;
    }
};