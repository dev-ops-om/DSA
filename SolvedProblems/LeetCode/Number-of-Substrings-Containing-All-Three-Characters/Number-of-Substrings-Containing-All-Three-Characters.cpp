class Solution {
public:
    int numberOfSubstrings(string s) {
           int left=0;
        int count=0;
        int ans=0;
        long long n=s.length();
        vector<int>freq(3,0);
        for(int right=0;right<n;right++){
            if(freq[s[right]-'a']==0){
                count++;
            }
            freq[s[right]-'a']++;
            
            while(count>2){
                freq[s[left]-'a']--;
                if(freq[s[left]-'a']==0){
                    count--;
                }
                left++;
                
            }
            ans+=(right-left+1);
        }
       long long atmost3=((n*(n+1))/2);
        return (atmost3-ans);
    }
};