class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> stk;
        for(int i = 0; i < s.size(); i++){
            if(stk.empty() || stk.back().first != s[i]){
                stk.push_back({s[i],1});
            }else if(++stk.back().second == k){
                stk.pop_back();
            }
        }
        string ans = "";
        for(int i = 0; i < stk.size(); i++){
            ans += string(stk[i].second,stk[i].first);
        }
        return ans;
    }
};