class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
     int n=s1.size();
     int m=s2.size();
     if(m<n)
     return false;
     string doubled=s1+s1;
     return (doubled.find(s2)!=string::npos);
        
    }
};