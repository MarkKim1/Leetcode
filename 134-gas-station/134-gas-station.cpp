class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0)){
            return -1;
        }
        int total = 0;
        int curr = 0;
        int pos = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i]-cost[i];
            curr +=gas[i] - cost[i];
            if(curr < 0){
                curr = 0;
                pos = i+1;
            }
        }
        return total < 0 ? -1 : pos;
    }
};