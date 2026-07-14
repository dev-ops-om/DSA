// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
      int ans=0;
    int temp=n;
      while(n>0){
          int rem=n%10;
          n=n/10;
          ans+=pow(rem,3);
      }
       return (temp==ans)?true:false; 
    }
};