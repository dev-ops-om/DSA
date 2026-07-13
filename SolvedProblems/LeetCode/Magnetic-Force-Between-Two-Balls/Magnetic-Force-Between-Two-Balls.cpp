class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int end=0;
        int start=1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            end=max(end,position[i]);
        }

        while(start<=end){
            int mid=start+(end-start)/2;

            int temp=position[0];
            int count=1;
            for(int i=1;i<n;i++){
              

                if(temp+mid<=position[i]){
                    count++;
                    temp=position[i];
                }
            }
            if(count>=m){
                ans=max(ans,mid);
                start=mid+1;

            }
            else{
                end=mid-1;

            }
        }
        return ans;
    }
};