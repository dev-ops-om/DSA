class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       int n=s.size();
       vector<int>lps(n,0);
       int len=0;
       int prefix=0;
       int suffix=1;
       while(suffix<n){
        if(s[suffix]==s[prefix]){
            prefix++;
            lps[suffix]=prefix;
            suffix++;
        }
        else{
            if(prefix!=0){
                prefix=lps[prefix-1];
            }
            else{
                lps[suffix]=0;
               suffix++;
            }
        }
       }
       int longest_overlap=lps[n-1];
       int base_unit_length=n-longest_overlap;

       return longest_overlap>0 && (n%base_unit_length==0);
    }
};