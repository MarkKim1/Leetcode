class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word(wordDict.begin(),wordDict.end());
        // cout << s.substr(0,4) << endl;
        // cout << s.substr(4,8) << endl;
        vector<bool> dp(s.size()+1);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] and word.find(s.substr(j,i-j)) != word.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
        //   0 1 2 3 4 5 6 7 8    
        //dp T F F F T F F F T
        
        //0 1 2 3 4 5 6 7
        //l e e t c o d e
    }
};