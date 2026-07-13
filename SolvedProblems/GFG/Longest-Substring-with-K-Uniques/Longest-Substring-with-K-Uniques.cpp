class Solution {
  public:
    int longestKSubstr(string &s, int k) {
    int n=s.length();
    int left=0;
    int ans=-1;
    int count=0;
vector<int>freq(26,0);
    for(int right=0;right<n;right++){
        if(freq[s[right]-'a']==0){
            count++;
        }
          freq[s[right]-'a']++;
        if(count==k){
            ans=max(ans,right-left+1);
        }
        while(count>k){
           freq[s[left]-'a']--;
           if(freq[s[left]-'a']==0)
           count--;
           left++;
         
        }
       
        
        
    }
    return ans;
        
    }
};