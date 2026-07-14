// User function Template for C++
void BST(int arr[],int &index,int lower,int upper,int N){
    
    if(index==N || arr[index]<lower|| arr[index]>upper)
    return;
    int value=arr[index++];
    BST(arr,index,lower,value,N);
    BST(arr,index,value,upper,N);
    
}
class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
     int index=0;
     BST(arr,index,INT_MIN,INT_MAX,N);
     return index==N;
        
    }
};