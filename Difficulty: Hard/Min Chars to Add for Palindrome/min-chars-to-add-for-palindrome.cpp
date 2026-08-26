class Solution {
  public:
    int minChar(string &s) {
        int n = s.size();
        int ans = 0;

string rev = s;
reverse(rev.begin(), rev.end());
string combined = s + "$" + rev;

vector<int>lps(2*n+1,0);
int i=0;
int j=1;
while(j<(2*n+1)){
    if(combined[i]==combined[j]){
        lps[j]=++i;
        j++;
    }
    else{
        if(i==0){
           lps[j]=0;
            j++;
        }
        else{
            i=lps[i-1];
        }
    }
}
return n-lps[2*n];
    }
};
