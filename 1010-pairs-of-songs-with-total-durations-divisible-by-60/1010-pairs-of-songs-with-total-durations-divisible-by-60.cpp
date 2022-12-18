class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        unordered_map<int,int> map;
        for(int i = 0; i < time.size(); i++){
            if(time[i]%60 ==0){
                result += map[0];
            }else{
                result += map[60 - time[i] % 60];
            }
            map[time[i]%60]++;
        }
        return result;
    }
};