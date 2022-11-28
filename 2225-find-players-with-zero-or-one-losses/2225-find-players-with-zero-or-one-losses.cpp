class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> winner;
        map<int,int> loser;
        vector<vector<int>> result(2);
        for(int i = 0; i < matches.size(); i++){
            winner[matches[i][0]]++;
            loser[matches[i][1]]++;
        }
        for(auto each_winner : winner){
            if(loser[each_winner.first] != 0){
                continue;
            }
            result[0].push_back(each_winner.first);
        }
        for(auto each_loser : loser){
            if(each_loser.second == 1){
                result[1].push_back(each_loser.first);
            } 
        }
        return result;
    }
};