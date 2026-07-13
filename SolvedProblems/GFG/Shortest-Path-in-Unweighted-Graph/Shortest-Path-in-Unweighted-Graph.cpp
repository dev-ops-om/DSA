class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
      //create an adjacency list
      
   vector<vector<int>> adj(V);

      int n=edges.size();   //total number of edges 
      for(int i=0;i<n;i++){
          int u=edges[i][0];
          int v=edges[i][1];
          
          adj[u].push_back(v);
           adj[v].push_back(u);
      }
      vector<int>dist(V,-1);
      vector<bool>visited(V,0);
      queue<int>q;
      q.push(src);
      visited[src]=1;
      dist[src]=0;
      
      while(!q.empty()){
          int node=q.front();
          q.pop();
         
         for(int j=0;j<adj[node].size();j++){
             
             if(visited[adj[node][j]])
             continue;
             
             visited[adj[node][j]]=1;
             q.push(adj[node][j]);
             dist[adj[node][j]]=dist[node]+1;
             
             
         }
      }
      return dist;
    }
};
