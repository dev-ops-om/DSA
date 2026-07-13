class Solution {
  public:
    int minCost(vector<int>& arr) {
        // min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<arr.size(); i++) {
            pq.push(arr[i]);
        }
        
        int sum = 0;
        while(pq.size() > 1) {
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            
            int cost = s1 + s2;
            sum += cost;
            
            pq.push(cost);
        }
        return sum;
    }
};