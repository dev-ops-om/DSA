class Solution {
public:
bool helper(char ch){
if(ch=='a'|| ch=='e'|| ch=='i' ||ch=='o'||ch=='u'){
    return true;
}
return false;
}
    int maxVowels(string s, int k) {
        int count=0;
        int ans=0;
        int left=0;
       int right=0;
      while(right<s.size()){
        if(helper(s[right]))
        count++;
       if((right-left+1)==k){
       ans=max(ans,count);

       if(helper(s[left])){
 count--;
 
       }
       left++;
       }
      
        right++;

      }
        return ans;
    }
};