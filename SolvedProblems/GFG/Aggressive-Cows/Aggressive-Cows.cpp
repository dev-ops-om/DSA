class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
       sort(stalls.begin(),stalls.end());
        int n=stalls.size();
   //     int max_dist=stalls[n-1];
   int end=0;
   for(int i=0;i<n;i++){
       end=max(stalls[i],end);
   }
        int ans=INT_MIN;
 int start=1;
 
    while(start<=end){
        int mid=start+(end-start)/2;
       int temp=stalls[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(temp+mid<=stalls[i]){
                count++;
                temp=stalls[i];
            }
        }
        if(count>=k){
            ans=max(ans,mid);
            start=mid+1;
        }
       else {
           end=mid-1; 
        }
        
    }
    return ans;
    }
};