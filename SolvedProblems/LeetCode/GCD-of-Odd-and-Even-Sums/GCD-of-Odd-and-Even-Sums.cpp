class Solution {
public:
int GCD(int a,int b){
    while(a>0 && b>0){
        if(a>b)
        a=a%b;
        else
        b=b%a;
    }
       if(a==0) return b;
    return a;
   
}
    int gcdOfOddEvenSums(int n) {
        int sumOfOdds=0;
        int sumOfEven=0;
        for(int i=1;i<=n;i++){
            sumOfEven+=2*i;
        }
        for(int i=1;i<=n;i++){
            sumOfOdds+=2*i-1;
        }
         
  
return GCD(sumOfOdds,sumOfEven);

    }
};