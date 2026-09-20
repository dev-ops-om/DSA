class Solution {
  public:
    int longestKSubstr(string &s, int k) {
      int n=s.size();
      vector<int>freq(26,0);
      int count=0;
      int max_len=-1;
      int left=0;
      for(int right=0;right<n;right++){
          if(freq[s[right]-'a']==0){
              count++;
          }
          freq[s[right]-'a']++;
          while (count > k) {
                          freq[s[left] - 'a']--;
                          if (freq[s[left] - 'a'] == 0) {
                             count--;
                          }
                          left++;
                      }
                      
                      if(count==k){
                          max_len=max(max_len,right-left+1);
                      }
      }
        return max_len;
    }
};