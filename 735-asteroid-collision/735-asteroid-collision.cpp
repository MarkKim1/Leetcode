class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        vector<int> ans;
        for(int i = 0; i < as.size(); i++){
            while(!ans.empty() && ans.back() > 0 && ans.back() < -as[i]){
                ans.pop_back();
            }
            if(ans.empty() || as[i] > 0 || ans.back() < 0){
                ans.push_back(as[i]);
            }
            else if(as[i] < 0 and ans.back() == -as[i]){
                ans.pop_back();
            }
        }
        return ans;
    }
};