// User function Template for C++
class Solution {
  public:
  void reverse(string &s,int start,int end){
      if(start>=end)
      return;
      
      swap(s[start],s[end]);
      
     reverse(s,start+1,end-1);
  }
    string revStr(string s) {
      reverse(s,0,s.length()-1);
        return s;
    }
};