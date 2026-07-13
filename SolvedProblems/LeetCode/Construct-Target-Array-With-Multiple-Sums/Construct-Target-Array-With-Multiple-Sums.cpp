class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> p;
        long long sum = 0;  
        for(int i = 0; i < target.size(); i++) {   
            p.push(target[i]);
            sum += target[i];
        }

        while(p.top() != 1) {
            int MaxEle = p.top();
            p.pop();
            long long RemSum = sum - MaxEle;

            if(RemSum <= 0 || RemSum >= MaxEle) return false;

            int Element = MaxEle % RemSum;
            if(Element == 0)
           {
            if(RemSum!=1)
            return 0;
            else 
            return 1;
           }
           sum=RemSum+Element;
           p.push(Element);
        }
        return true;
    }
};
