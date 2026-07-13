class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
           priority_queue<int, vector<int>, greater<int>> pq; // min-heap
        vector<int> result;

        for(int i = 0; i < n; i++) {
            pq.push(arr[i]);

            if(pq.size() > k) {
                pq.pop(); // keep only k largest
            }

            if(pq.size() < k) {
                result.push_back(-1); // not enough elements yet
            } else {
                result.push_back(pq.top()); // kth largest
            }
        }

        return result;

    }
};