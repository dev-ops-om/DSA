bool myComp(const pair<char,int>&a,const pair<char,int>&b){
        return a.second>b.second;
    };
class Solution {
public:
 
    string frequencySort(string s) {
       vector<pair<char,int>>vec(128);

    for(char &ch:s){
        int freq=vec[ch].second;
        vec[ch]={ch,freq+1};
    }
 
    sort(vec.begin(),vec.end(),myComp);
    string result="";
    for(int i=0;i<128;i++){
        if(vec[i].second>0){
            char ch=vec[i].first;
            int freq=vec[i].second;
            string temp=string(freq,ch);
            result+=temp;
        }
    }
    return result;
    }
};