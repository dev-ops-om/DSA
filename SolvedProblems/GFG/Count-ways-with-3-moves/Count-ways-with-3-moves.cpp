
class Solution {
  public:
    // Function to count the number of ways in which frog can reach the top.
    int countWays(int n) {

      if(n==1|| n==0){
          return 1;
      }
      if(n==2){
        return 2;
        }
     long long a = 1; // ways(0)
        long long b = 1; // ways(1)
        long long c = 2; // ways(2)
        long long next;

        for (int i = 3; i <= n; i++) {
            next = (a + b + c) ;
            a = b;
            b = c;
            c = next;
        }

        return c;
    }
};
