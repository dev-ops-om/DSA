class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
       sort(arr.begin(), arr.end());
        int ans=0;
        int diff=INT_MAX;
        
        for(int i=0;i<arr.size()-2;i++){
            
            if(i>0 && arr[i]==arr[i-1]){
                continue;
            }
            int left=i+1;
            int right=arr.size()-1;
            
            while(left<right){
                int sum=arr[i]+arr[left]+arr[right];
                
                int currdiff=abs(sum-target);
                if(currdiff<diff){
                    diff=currdiff;
                    ans=sum;
                }
                else if(currdiff==diff){
                    ans=max(ans,sum);
                }
                
                if(sum>target){
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return ans;
    }
};