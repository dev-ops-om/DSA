class Solution {

    private:
    bool isalphaNum(char ch){
        if((tolower(ch)>='a' && tolower(ch)<='z' )||(ch>='0' && ch<='9')){
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(string s) {
      int left=0;
      int right=s.size()-1;
      while(left<right){
            if(!isalphaNum(tolower(s[left]))){
                left++;
                continue;
            }
            if(!isalphaNum(tolower(s[right]))){
                right--;
                continue;
            }
        if(tolower(s[left])!=tolower(s[right])){
            return false;
        }
        left++;
        right--;
       
      }
      return true;
    }
};