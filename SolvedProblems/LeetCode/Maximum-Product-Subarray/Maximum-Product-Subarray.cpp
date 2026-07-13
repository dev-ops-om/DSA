class Solution {
public:
    int maxProduct(vector<int>& arr) {

        int ans = arr[0];   // important change
        int currMin = arr[0];
        int currMax = arr[0];

        for(int i = 1; i < arr.size(); i++) {
   int temp = max({ arr[i], arr[i] * currMax,
     	arr[i] * currMin });


     currMin = min({ arr[i], arr[i] * currMax,
       	arr[i] * currMin });    
        currMax=temp;                                   
           
            ans = max(ans,currMax);
        }

        return ans;
    }
};
