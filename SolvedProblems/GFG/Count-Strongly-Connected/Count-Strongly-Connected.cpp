//Position this line where user code will be pasted.
class Solution {
  public:
  void topological(int node,vector<vector<int>> &adj, vector<bool>&visited,stack<int>&s){
      visited[node]=1;
      
      for(int j=0;j<adj[node].size();j++){
          if(!visited[adj[node][j]])
          topological(adj[node][j],adj,visited,s);
      };
      s.push(node);
  }
  
  void DFS(int node,vector<vector<int>> &adj, vector<bool>&visited){
      visited[node]=1;
      for(int j=0;j<adj[node].size();j++){
          if(!visited[adj[node][j]])
          DFS(adj[node][j],adj,visited);
      }
  }
    int kosaraju(vector<vector<int>> &adj) {
        int v=adj.size();
       
        stack<int>s;
        vector<bool>visited(v,0);
        for(int i=0;i<v;i++){
            if(!visited[i])
            topological(i,adj,visited,s);
        }
         vector<vector<int>>adj2(v);
      for(int i=0;i<v;i++){
          for(int j=0;j<adj[i].size();j++){
              int u=i;
              int v=adj[i][j];
              adj2[v].push_back(u);
          }
      }
      
      for(int i=0;i<v;i++)
      visited[i]=0;
      int scc=0;
      while(!s.empty()){
          int node=s.top();
          s.pop();
          if(!visited[node]){
              scc++;
              
              DFS(node,adj2,visited);
          }
      }
      return scc;
      
    }
};