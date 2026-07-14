class Solution {
public:
    void segregateElements(vector<int>& arr) {
        vector<int> temp;
        
        // store positive elements
        for (int x : arr) {
            if (x >= 0)
                temp.push_back(x);
        }
        
        // store negative elements
        for (int x : arr) {
            if (x < 0)
                temp.push_back(x);
        }
        
        // copy back to original array
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = temp[i];
        }
    }
};