class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int k=p.size();
  vector<int>result;
        if(n<k){
            return {};
        }
        vector<int>win_freq(26,0);
        vector<int>p_freq(26,0);
        for(int i=0;i<k;i++){
            win_freq[s[i]-'a']++;
            p_freq[p[i]-'a']++;
        }
if(win_freq==p_freq){
    result.push_back(0);
}
        for(int i=k;i<n;i++){
            win_freq[s[i]-'a']++;
            win_freq[s[i-k]-'a']--;

            if(win_freq==p_freq){
                result.push_back(i-k+1);
            }
        }
        return result;
    }
};