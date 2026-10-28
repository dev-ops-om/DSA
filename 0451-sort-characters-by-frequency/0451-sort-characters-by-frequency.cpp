

bool lambda(const pair<char, int>& a, const pair<char, int>& b) {
    return a.second > b.second;   //decreasing order
}
class Solution {
public:
 
    string frequencySort(string s) {
      vector<pair<char,int>>freq(128);

      for(char ch:s){
        int temp=freq[ch].second;
        freq[ch]={ch,temp+1};
      }

      sort(freq.begin(),freq.end(),lambda);
      string ans="";
        for(int i=0;i<128;i++){
            if(freq[i].second>0){
                int temp=freq[i].second;
                char ch=freq[i].first;
                ans+=string(temp,ch);
            }
        }
    return ans;


    }
};