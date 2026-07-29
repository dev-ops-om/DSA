class Solution {
  public:
    // Function to remove all occurrences of the character from the string
    void removeCharacter(string &s, char c) {
      int left=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=c){
            s[left]=s[i];
            left++;
            }
            
        }
      s=s.substr(0,left);
    }
};