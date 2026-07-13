class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // adjacency list
        vector<int> adj[n];
        for (int i = 0; i < relations.size(); i++) {
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
        }

        // indegree
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                indeg[adj[i][j]]++;
            }
        }

        // queue for topo sort
        queue<int> q;
        vector<int> coursetime(n, 0);

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                coursetime[i] = 0; // no prereq, start at 0
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 0; j < adj[node].size(); j++) {
                int nxt = adj[node][j];
                indeg[nxt]--;
                if (indeg[nxt] == 0) q.push(nxt);

                // update max time for next course
                coursetime[nxt] = max(coursetime[nxt], coursetime[node] + time[node]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, coursetime[i] + time[i]);
        }
        return ans;
    }
};