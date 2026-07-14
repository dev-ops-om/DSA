// User function Template for C++

bool find4Numbers(int A[], int n, int target) {
    int sum=0;
    sort(A,A+n);
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            
            int left=j+1;
            int right=n-1;
            
            while(left<right){
                sum=A[i]+A[j]+A[left]+A[right];
                
                if(sum==target){
                    return true;
                }
                else if(sum>target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
       
    }
     return false;
}