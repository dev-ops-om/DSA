class Solution {
public:
    string minWindow(string s, string t) {
        int m=t.length();
        vector<int>freq(128,0);
        for(int i=0;i<m;i++){
            freq[t[i]]++;
        }
      string ans="";
        int length=INT_MAX;
        int end=0;
       int  startind=-1;
        int start=0;
        while(end<s.size()){
            if(freq[s[end]]>0){
                m--;
            }
              freq[s[end]]--;
            while(!m && start<=end){
                if(end-start+1<length){
                    length=end-start+1;
                    startind=start;
                }
                freq[s[start]]++;
                if(freq[s[start]]>0){
                    m++;
                }
                start++;
            }
          
            end++;
        }
        return (length==INT_MAX?"":s.substr(startind,length));
    }
};