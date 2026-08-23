class Solution {

   vector<int>helper(string &s){
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
    return lps;
   }
public:
   vector<int> search(string &pat, string &txt) {

vector<int>lps;
lps=(helper(pat));
vector<int>ans;
int second=0;
int first=0;
while(second<pat.size()&& first<txt.size()){
    if(txt[first]==pat[second]){
        first++;
        second++;
    }
    else{
        if(second==0){
            first++;
        }
        else{
            second=lps[second-1];
        }
    }
    if(second==pat.size()){
    
   ans.push_back(first-second);
    second = lps[second - 1];
}
}



return ans;

    }
};