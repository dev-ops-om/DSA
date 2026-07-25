class Solution {
  public:
    int maxDepth(string &s) {
       int currentMax=0;
       int Max=0;
       int n=s.size();
       int ans=0;
       for(int i=0;i<s.size();i++){
           char ch=s[i];
           if(ch=='(')
           currentMax++;
           else if(ch==')')
           {
               if(currentMax>0)
               currentMax--;
           }
           
           ans=max(ans,currentMax);
       }
        return ans;
    }
};