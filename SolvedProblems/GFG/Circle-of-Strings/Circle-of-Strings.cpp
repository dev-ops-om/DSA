// User function Template for C++
 void DFS(int node,vector<int>adj[],vector<bool>&visited){
      visited[node]=1;
      for(int j=0;j<adj[node].size();j++){
          if(!visited[adj[node][j]])
          DFS(adj[node][j],adj,visited);
      }
  }
class Solution {
  public:
    int isCircle(vector<string> &a) {
      int n=a.size();
       vector<int>indeg(26,0);
      vector<int>outdeg(26,0);
      vector<int>adj[26];
      for(int i=0;i<n;i++){
          string temp=a[i];
        int u=temp[0]-'a';
        int v=temp[temp.size()-1]-'a';
        adj[u].push_back(v);
        outdeg[u]++;
        indeg[v]++;
        
          
      }
      
      
      for(int i=0;i<26;i++){
          if(indeg[i]!=outdeg[i])
          return 0;
      }
      
      vector<bool>visited(26,0);
      
     DFS(a[0][0]-'a',adj,visited);
      
        for(int i=0;i<26;i++){
            if(indeg[i]&&!visited[i])
            return 0;
        }
        return 1;
    }
};