class Solution {
  public:
    string sortString(string &s) {
vector<int>freq(26,0);
for(char ch:s){
    freq[ch-'a']++;
    
}
string ans="";
for(int i=0;i<26;i++){
    char c='a'+i;
    while(freq[i]){
        ans+=c;
        freq[i]--;
    }
}
return ans;
    }
};