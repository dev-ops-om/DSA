class Solution {
  public:
    string findOrder(vector<string> &words) 
    {
        //first we have to find the number of diffrent letters
        unordered_set<char>s;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                s.insert(words[i][j]);
            }
        }
        
        int k=s.size();
        
        unordered_map<char,vector<char>>adj;
        unordered_map<char,int>InDeg;
        
        for(auto it=s.begin();it!=s.end();it++)
        {
            InDeg[*it]=0;
        }
        
        //now we have to compare two continous strings for finding the adj list
        //the first letter where they will vary will give us the order
        
        for(int i=1;i<words.size();i++)
        {
            int index=0;
            bool finded=0;
            while(index<words[i-1].size() && index<words[i].size())
            {
                if(words[i-1][index]!=words[i][index])
                {
                    adj[words[i-1][index]].push_back(words[i][index]);
                    InDeg[words[i][index]]++;
                    finded=1;
                    break;
                }
                
                index++;
            }
            
            if(!finded && words[i-1].size()>index)
            {
                return "";
            }
            
        }
        
        //now we just have to return the topo sort for that first we have to find char with 0 InDeg
        queue<char>q;
        string ans;
        for(auto it=InDeg.begin();it!=InDeg.end();it++)
        {
            if(!it->second)
            {
                q.push(it->first);
            }
        }
        
        while(!q.empty())
        {
            char Node = q.front();
            q.pop();
            
            ans+=Node;
            
            //now we have to decrease the InDeg of all the Nodes connected to it since this task has been excuted
            for(int i=0;i<adj[Node].size();i++)
            {
                InDeg[adj[Node][i]]--;
                if(!InDeg[adj[Node][i]])
                {
                    //it means all the necessary tasks to excute this task has been completed 
                    //so now we can execute this task
                    q.push(adj[Node][i]);
                }
            }
        }
        
        if(ans.size()==k)
        {
            return ans;
        }
        
        string temp;
        return temp;
        
    }
};