class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){

            //we are using swap just to ensure that the new swapped element will also get its correct position  
            while(arr[i]>=1 && arr[i]<=n && arr[i]!=arr[arr[i]-1]){
                swap(arr[i],arr[arr[i]-1]);
            }
        }


        for( int i=1;i<=n;i++){
            if(i!=arr[i-1]){
                return i;
            }
        }

        return n+1;
    }
};