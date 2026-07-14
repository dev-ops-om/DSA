class Solution {
public:

    int findparent(int u, vector<int>& parent) {
        if (u == parent[u]) return u;
        return parent[u] = findparent(parent[u], parent);
    }

    void unionbyrank(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = findparent(u, parent);
        int pv = findparent(v, parent);

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int spanningTree(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back(make_pair(v, wt));
            adj[v].push_back(make_pair(u, wt));
        }

        // Collect all edges into temp
        vector<pair<int, pair<int, int>>> temp;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                temp.push_back({adj[i][j].second, {i, adj[i][j].first}});
            }
        }

        // Heapify the edge list
        priority_queue< pair<int, pair<int, int>>,
                        vector<pair<int, pair<int, int>>>,
                        greater<pair<int, pair<int, int>>> > pq(temp.begin(), temp.end());

        // DSU setup
        vector<int> parent(V);
        vector<int> rank(V, 0);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int cost = 0;
        int count = 0;

        // Kruskal main loop
        while (!pq.empty() && count < V - 1) {
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();

            if (findparent(u, parent) != findparent(v, parent)) {
                cost += wt;
                unionbyrank(u, v, parent, rank);
                count++;
            }
        }

        return cost;
    }
};