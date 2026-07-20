class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int m=goal.size();
if(m<n){
    return false;
}
        string doubled=s+s;
         return doubled.find(goal)!=string::npos;
    }
};