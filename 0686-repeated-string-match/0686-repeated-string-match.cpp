class Solution {
public:
vector<int>buildLPS(string& s){
    int m=s.size();
    int prefix=0;
    int suffix=1;
vector<int>lps(m,0);
    while(suffix<m){
        if(s[prefix]==s[suffix]){
            prefix++;
            lps[suffix]=prefix;
            suffix++;
        }
        else{
            if(prefix>0){
                prefix=lps[prefix-1];
            }else{
                lps[suffix]=0;
                suffix++;
            }
        }
    }
    return lps;
}

bool kmpSearch(string &a,string &b,vector<int>&lps){
    int n=a.size();
    int m=b.size();

    int i=0;
    int j=0;
   while(i<n){
    if(a[i]==b[j]){
        i++;
        j++;
        if(j==m)
        return true;
    }
    else{
        if(j!=0){
            j=lps[j-1];

        }else{
            i++;
        }
    }
   }
   return false;
}


    int repeatedStringMatch(string a, string b) {
        vector<int>lps=buildLPS(b);
        string temp=a;
        int repeated=1;
        while(temp.size()<b.size()){
            temp+=a;
            repeated++;
        }

        if(kmpSearch(temp,b,lps))
        return repeated;

        temp+=a;
        repeated++;

      if(kmpSearch(temp,b,lps))
      return repeated;

      return -1;
    }
};