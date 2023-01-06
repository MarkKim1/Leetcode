class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int curr = 0;
        int result = 0;
        for(int i = 0; i < costs.size(); i++){
            curr+=costs[i];
            result++;
            if(curr >= coins){
                break;
            }
        }
        if(curr > coins){
            result--;
        }
        return result;
    }
};