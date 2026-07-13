class Solution {
public:

bool check(int node,vector<vector<int>>& adj,vector<int>&color){
    for(int j=0;j<adj[node].size();j++){
        if(color[adj[node][j]]==-1)
        {
            color[adj[node][j]]=(color[node]+1)%2;
            if(!check(adj[node][j],adj,color))
            return 0;
        }
        else{
            if(color[node]==color[adj[node][j]])
            return 0;
        }
    }
    return 1;
}
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<int>color(V,-1);

        // Build adjacency list (undirected graph)
        for (auto &e : edges) {
            int u = e[0];
            int w = e[1];
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
for(int i=0;i<V;i++){
    if(color[i]==-1)
    {
        color[i]=0;
        if(!check(i,adj,color))
        return 0;
    }
}
return 1;

    }
};
