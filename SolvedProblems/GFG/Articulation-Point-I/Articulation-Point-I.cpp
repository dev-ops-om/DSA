// User function Template for C++
void DFS(int node,int parent,vector<int> adj[],vector<bool>&visited,vector<int>&disc,vector<int>&low,vector<bool>&artpoint,int count){
    disc[node]=low[node]=count;
    int child=0;
    visited[node]=1;
    for(int j=0;j<adj[node].size();j++){
        int neib=adj[node][j];
        if(neib==parent)
        continue;
        else if(visited[neib])
        {
            low[node]=min(low[node],disc[neib]);
        }
        else{
            child++;
            count++;
            DFS(neib,node,adj,visited,disc,low,artpoint,count);
low[node]=min(low[node],low[neib]);
            if(disc[node]<=low[neib] && parent!=-1){
              artpoint[node]=1;

            }
           
        }
    }
    if(child>1 &&parent==-1){
        artpoint[node]=1;
    }
}

class Solution {
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
      vector<bool>artpoint(V,0);
      vector<int>disc(V);
      vector<int>low(V);
      vector<bool>visited(V,0);
      
      int timer=0;
      DFS(0,-1,adj,visited,disc,low,artpoint,timer);
      vector<int>ans;
      for(int i=0;i<V;i++){
          if(artpoint[i])
          ans.push_back(i);
      }
      if(ans.size()==0)
      ans.push_back(-1);
      return ans;
    }
};