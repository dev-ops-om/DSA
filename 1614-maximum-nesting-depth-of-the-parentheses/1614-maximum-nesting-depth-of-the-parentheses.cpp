class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int temp=0;
        int ans=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='(')
            temp++;
            if(ch==')')
            temp--;

            ans=max(ans,temp);
        }
        return ans;
    }
};