class Solution {
  public:
    int heapHeight(int n, int arr[]) {
        if(n==1)
        return 1;
    int count=0;
    while(n!=1){
        n=n/2;
        count++;
        
    }
    return count;
    
    }
};