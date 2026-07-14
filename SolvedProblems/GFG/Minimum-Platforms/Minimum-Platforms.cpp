class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int n = arr.size();
        int i = 0, j = 0;
        int platforms = 0, result = 0;

        while(i < n && j < n) {
            if(arr[i] <= dep[j]) {
                platforms++;   // train arrives
                result = max(result, platforms);
                i++;
            } else {
                platforms--;   // train departs
                j++;
            }
        }
        return result;
    }
};

