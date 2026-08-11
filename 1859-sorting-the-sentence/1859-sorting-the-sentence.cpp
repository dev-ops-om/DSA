class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string word;
        vector<string>result(10);


    while(ss>>word){
      int pos=word.back()-'0';
      word.pop_back();
      result[pos]=word;
    }
    string ans="";
    for(int i=1;i<10;i++){
        if(!result[i].empty()){

            if(!ans.empty()){
                ans+=" ";
            }
            ans+=result[i];

        }
    }
    return ans;
    }
};