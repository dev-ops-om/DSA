class Solution {
public:
    string longestPrefix(string s) {
     int pre=0;
    int suf=1;
    vector<int>lps(s.size(),0);
    while(suf<s.size()){
        if(s[suf]==s[pre]){
            pre++;
            lps[suf]=pre;
            suf++;
        }else{
            if(pre!=0){
                pre=lps[pre-1]; //fallback to the previous known longest prefix 
            }
            else{
                lps[suf]=0;
                suf++;
            }
        }
        
    }
    int length=lps[s.size()-1];
    return s.substr(0,length);
    }
};