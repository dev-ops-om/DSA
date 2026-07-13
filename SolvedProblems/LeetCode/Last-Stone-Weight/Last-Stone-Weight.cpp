class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>p;
        for(int i=0;i<stones.size();i++){
            p.push(stones[i]);
        }
  int weight=0;
        while(p.size()>1){
           int x=p.top();
           p.pop();
           int y=p.top();
            p.pop();
           weight=x-y;

           if(weight)
           p.push(weight);

        }

        if(p.empty())
        return 0;
        return p.top();

    }
};