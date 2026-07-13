class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x ) {
        int n=arr.size();
            // return index of first number
    // greater than or equal to x
    int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    // return index of first number
    // greater than x
    int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;

    // If x is not present
    if (first == n||arr[first] != x) {
        first = -1;
        last = -1;
    }
    return {first,last};
    }
};