class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> stk;
        for(int i = 0; i < s.size(); i++){
            if(!stk.empty() and stk.back().first == s[i]){
                if(stk.back().second == k-1){
                    for(int j = 0; j < k-1; j++){
                        stk.pop_back();
                    }
                }else{
                    stk.push_back(make_pair(s[i],stk.back().second + 1));
                }
            }else{
                stk.push_back(make_pair(s[i],1));
            }
        }
        string ans = "";
        for(int i = 0; i < stk.size(); i++){
            ans.push_back(stk[i].first);
        }
        return ans;
    }
};