class Solution {
public:
int wincal(int n,int k){
     if(n==1){
            return 0;
        }
        return (wincal(n-1,k)+k)%n;
}

    int findTheWinner(int n, int k) {
       return wincal(n,k)+1;
    }
};