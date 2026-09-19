class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(128,0);
        int start=0;
        int min_len = INT_MAX, start_ind = -1;
        int m=t.size();
        int end=0;
        for(char ch:t){
            freq[ch]++;
        }
        while(end<s.size()){
            if(freq[s[end]]>0){
                m--;
            }
            freq[s[end]]--;

            while(!m && start<=end){
                if(end-start+1<min_len){
                    min_len=end-start+1;
                    start_ind=start;


                }
                freq[s[start]]++;
                if(freq[s[start]]>0){
                    m++;
                }
                start++;

            }
            end++;

        }

  return min_len==INT_MAX?"":s.substr(start_ind,min_len);
    }
};