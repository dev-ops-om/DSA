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
     for(int i=0;i<k;i++){
        if(helper(s[i]))
        count++;
     }
     ans=count;

     for(int right=k;right<s.size();right++){
        if(helper(s[right]))
        count++;
        if(helper(s[left])){
        count--;

}
ans=max(ans,count);
left++;

        
     }
     return ans;
    }
};