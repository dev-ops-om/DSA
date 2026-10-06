class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int m=needle.size();
        int n=haystack.size();
        for(int i=0;i<=n-m;i++){
            int first=i;
            int second=0;
            while(second<m){
                if(haystack[first]!=needle[second])
                break;

                else{
                    first++;
                    second++;
                }

            if(second==m){
                return first-second;
            }

            }
        }
        return -1;
    }
};