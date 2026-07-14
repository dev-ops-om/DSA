class Solution {
public:
    int countOccurence(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> candidates;

        // First pass: find potential candidates
        for(int num : arr) {
           if(candidates.count(num)) {
                candidates[num]++;
            } else if(candidates.size() < k-1) {
                candidates[num] = 1;
            } else {
                // decrement all counts
                vector<int> toRemove;
                for(auto &p : candidates) {
                    p.second--;
                    if(p.second == 0) 
                    toRemove.push_back(p.first);
                }
                for(int rem : toRemove) 
                candidates.erase(rem);
            }
        }

        // Second pass: verify actual frequencies
        unordered_map<int,int> freq;
        for(int num : arr) freq[num]++;

        int ans = 0;
        for(auto &p : candidates) {
            if(freq[p.first] > n/k) ans++;
        }
        return ans;
    }
};