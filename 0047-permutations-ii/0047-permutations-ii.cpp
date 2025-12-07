class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> count;
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        vector<int> comb;
        backtrack(result,comb,count, nums.size());
        return result;
    }
    void backtrack(vector<vector<int>>& result, vector<int>& comb, unordered_map<int,int>& count, int a){
        if(comb.size() == a){
            result.push_back(comb);
            return;
        }
        for(auto& each: count){
            int num = each.first;
            int counter = each.second;
            if(counter == 0) continue;
            comb.push_back(num);
            each.second--;
            backtrack(result,comb,count,a);
            comb.pop_back();
            each.second++;
        }
    }
};