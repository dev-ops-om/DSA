class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int first=0;
        int maxlen=0;
        vector<int>count(256,0);
        int second=0;
while(second<n){
 
        while(count[s[second]] && first<=second){
            count[s[first]]=0;
            first++;
        }
   count[s[second]]=1;
   maxlen=max(maxlen,second-first+1);
   second++;
}

return maxlen;
    }
};