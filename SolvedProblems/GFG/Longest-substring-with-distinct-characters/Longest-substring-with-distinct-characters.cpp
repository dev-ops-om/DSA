class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
           vector<int>freq(26,0);
        int n=s.length();
        int count=0;
        int left=0;
        int ans=0;
        for(int right=0;right<n;right++){
            

            
            while(freq[s[right]-'a']==1){
                freq[s[left]-'a']=0;
               
                left++;
            }
            ans=max(right-left+1,ans);
            freq[s[right]-'a']=1;
        }
        return ans;
    }
};
