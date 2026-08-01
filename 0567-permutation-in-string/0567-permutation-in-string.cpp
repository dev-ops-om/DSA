class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();

        if(n1>n2)
        return false;
 
 vector<int>freq_1(26,0);
  vector<int>freq_2(26,0);

        for(char &ch:s1)
        freq_1[ch-'a']++;

        int i=0;
        int j=0;

        while(j<n2){

            freq_2[s2[j]-'a']++;

            if((j-i+1)>n1){
                 freq_2[s2[i]-'a']--;
                 i++;
            }

            if((j-i+1)==n1 && freq_1==freq_2)
            return true;

            j++;
        }

        return false;
    }
};