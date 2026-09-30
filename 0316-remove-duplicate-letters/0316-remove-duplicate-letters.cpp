class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>last_idx(26,0);
        for(int i=0;i<s.size();i++){
            last_idx[s[i]-'a']=i;
        }
        vector<bool>seen(26,false);

        string result="";
        for(int i=0;i<s.size();i++){
            char c=s[i];

            if(seen[c-'a'])
            continue;

            while(!result.empty() && result.back()>c && last_idx[result.back()-'a']>i){
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(c);
            seen[c-'a']=true;
        }
        return result;
    }
};