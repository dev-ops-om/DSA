class Solution {
  public:
  void gA(vector<vector<int>>& maze,int r,int c,vector<string>&ans, string path, vector<vector<bool>>& vis){
      int n=maze.size();
      
      if(r<0|| c<0||r>=n||c>=n|| maze[r][c]==0|| vis[r][c]==true){
          return;
      }
      if(r==n-1&&c==n-1){
          ans.push_back(path);
          return;
      }
      vis[r][c]=true;
      gA(maze,r+1,c,ans,path+"D",vis);
       
        gA(maze,r,c-1,ans,path+"L",vis);
        
         gA(maze,r,c+1,ans,path+"R",vis);
         gA(maze,r-1,c,ans,path+"U",vis);
         vis[r][c]=false;
  }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        int n=maze.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
       vector<string>ans;
       string path="";
      gA(maze,0,0,ans,path,vis);
      return ans;
    }
};