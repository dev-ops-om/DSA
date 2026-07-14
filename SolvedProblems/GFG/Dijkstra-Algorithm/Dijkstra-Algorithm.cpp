class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int S) {
       
      vector<pair<int,int>>adj[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int weight=edges[i][2];
            
            adj[u].push_back(make_pair(v,weight));
             adj[v].push_back({u, weight}); 
            
        }
        vector<bool>explored(V,0);
        vector<int>dist(V,INT_MAX);
        dist[S]=0;
      
         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
         p.push({0,S});
         
         while(!p.empty()){
             int node=p.top().second;
             p.pop();
             if(explored[node]==1)
             continue;
             explored[node]=1;
             
               for(int j=0;j<adj[node].size();j++){
            int neighbour=adj[node][j].first;
            
            int weight=adj[node][j].second;
           if(!explored[neighbour]&&(dist[node]+weight<dist[neighbour])) {
               dist[neighbour]=dist[node]+weight;
               p.push({dist[neighbour],neighbour});
           }
        }
         }
      return dist;
        
    }
};