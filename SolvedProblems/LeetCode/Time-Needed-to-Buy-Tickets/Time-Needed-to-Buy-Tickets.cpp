class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int timer=0;
        for(int i=0;i<tickets.size();i++){
            if(i<=k)
            timer+=min(tickets[k],tickets[i]);
            else
            timer+=min(tickets[k]-1,tickets[i]);
        }
        return timer;
    }
};