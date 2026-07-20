class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>mapS(256,0);
          vector<int>mapT(256,0);

          for(int i=0;i<s.size();i++){
            char S=s[i];
            char T=t[i];

            if(mapS[S]!=0 && mapS[S]!=T)return false;
             if(mapT[T]!=0 && mapT[T]!=S)return false;

             mapS[S]=T;
             mapT[T]=S;
          }
        return true;
    }
};