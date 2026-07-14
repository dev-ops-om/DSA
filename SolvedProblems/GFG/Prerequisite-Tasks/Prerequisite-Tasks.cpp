class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
       
       vector<int>adj[N];
       vector<int> indeg(N, 0);
       for(int i=0;i<P;i++){
           adj[prerequisites[i].second].push_back(prerequisites[i].first);
           indeg[prerequisites[i].first]++;
       }
        queue<int>q;
         for (int i = 0; i < N; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        
        int count=0;
        
        while(!q.empty()){
            int node =q.front();
            q.pop();
            count++;
            
            for(int j=0;j<adj[node].size();j++){
                indeg[adj[node][j]]--;
                if(!indeg[adj[node][j]])
                q.push(adj[node][j]);
                
            }
        }
  return count==N;
    }
};