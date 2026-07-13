class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> dq;   // stores indices
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++) {

        // 1. Remove index out of window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // 2. Remove smaller elements
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        // 3. Add current index
        dq.push_back(i);

        // 4. Store answer when window is ready
        if (i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }

    return ans;
    }
};