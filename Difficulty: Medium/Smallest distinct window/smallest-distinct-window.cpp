class Solution {
  public:
    int findSubString(string& str) {
       int n=str.size();
       int total_unique=0;
       vector<int>freq(26,-1);
       for(int i=0;i<n;i++){
           if(freq[str[i]-'a']==-1){
           total_unique++;
               freq[str[i]-'a']=0;
           }
       }
       int current_unique=0;
       int right=0;
       int ans=n;
       int left=0;
       while(right<n){
           if(freq[str[right]-'a']==0){
               current_unique++;
             
           }
           freq[str[right]-'a']++;
           while(current_unique==total_unique){
               ans=min(ans,right-left+1);
               freq[str[left]-'a']--;
        
               if(freq[str[left]-'a']==0){
                   current_unique--;
               }
                      left++;
           }
           right++;
       }
       return ans;
        
    }
};