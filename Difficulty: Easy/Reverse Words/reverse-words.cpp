class Solution {
  public:
    string reverseWords(string &s) {
       
string ans="";
string word="";
int n=s.size();

for(int i=0;i<n;i++){
    word="";
    while(s[i]!='.' && i<n){
        word+=s[i];
        i++;
    }
    if(word.length()>0){
        ans=word+'.'+ans;
    }
}
return ans.substr(0,ans.size()-1);
    }
};