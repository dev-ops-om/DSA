class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            int start=arr[i][0];
            int end=arr[i][1];
int lastend=ans.back()[1];
            if(start<=lastend){
                ans.back()[1]=max(lastend,end);
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};