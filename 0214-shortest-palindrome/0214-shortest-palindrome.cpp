class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string combined=s+'$'+rev;
        int n=combined.size();

        vector<int>lps(n,0);
        int first=0;
        int second=1;
        while(second<n){
            if(combined[first]==combined[second]){
                lps[second]=++first;
                second++;
            }
            else {
                if(first!=0){
                    first=lps[first-1];

                }
                else{
                    lps[second]=0;
                    second++;
                }
            }
        }
        int temp=s.size()-lps[n-1];
        int start=lps[n-1];
        string subStr=s.substr(start,s.size());

     reverse(subStr.begin(),subStr.end());

        return subStr+s;

    }
};