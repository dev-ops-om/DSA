class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currGas=0;
        int start=0;
int s1=0;
int s2=0;

        for(int i=0;i<gas.size();i++){
s1+=gas[i];
s2+=cost[i];


        }
        if(s1<s2){
    return -1;
}
        for(int i=0;i<gas.size();i++){
            currGas=currGas+gas[i]-cost[i];
            

            if(currGas<0){
                currGas=0;
                start=i+1;
            }
        }
        return start;
    }
};