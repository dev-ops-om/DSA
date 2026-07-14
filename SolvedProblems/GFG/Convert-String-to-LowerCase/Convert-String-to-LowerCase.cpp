// User function Template for C++

class Solution {
  public:
    string toLower(string& s) {
     int n=s.length();
     for(int i=0;i<n;i++){
         
       if (s[i] >= 'A' && s[i] <= 'Z') {
    s[i] = s[i] - 'A' + 'a';
}

         
     }
     return s;
    }
};