class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto &e : edges) {
            int u = e[0];
            int w = e[1];
            adj[u].push_back(w);
        }

        vector<int> ans;
        vector<int> indeg(V, 0);

        // Compute indegree
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                indeg[adj[i][j]]++;
            }
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        // Process queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int j = 0; j < adj[node].size(); j++) {
                indeg[adj[node][j]]--;
                if (indeg[adj[node][j]] == 0) {
                    q.push(adj[node][j]);
                }
            }
        }

        return ans;
    }
};