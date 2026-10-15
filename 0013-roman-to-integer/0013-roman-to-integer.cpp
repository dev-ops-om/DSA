class Solution {
public:
    int romanToInt(string s) {
        unordered_map<int,int>mp={
               {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int sum=0;
        int n=s.size();
for(int i=0;i<n-1;i++){
int value=mp[s[i]];
if(value>=mp[s[i+1]]){
    sum+=value;
}
else{
    sum-=value;
}

}
sum+=mp[s[n-1]];

return sum;
    }
};