class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0;
        int j = 0;
        int result = 0;
        while(i < neededTime.size()){
            int curr = 0;
            int curr_max = INT_MIN;
            while(i < neededTime.size() and colors[i] == colors[i+1]){
                curr_max = max(neededTime[i],curr_max);
                curr+=neededTime[i];
                i++;
                if(colors[i] != colors[i+1]){
                    curr_max = max(neededTime[i],curr_max);
                    curr+=neededTime[i];
                    break;
                }
            }
            if(curr_max != INT_MIN){
                result += curr-curr_max;
            }else{
                i++;
            }
        }
        
        return result;
    }
};