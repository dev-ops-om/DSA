class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
    
        int maxlen=0;
int ans=0;
        vector<int>count(256,0);

for(int right=0;right<s.size();right++){
    while(count[s[right]] && left<right){
    count[s[left]]=0;
    left++;


    }
    count[s[right]]=1;
    maxlen=right-left+1;
   ans=max(maxlen,ans);

}
return ans;
    }
};