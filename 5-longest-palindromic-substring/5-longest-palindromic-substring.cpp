class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size()));
        if(s.size() == 1) return s;
        for(int i = 0; i < s.size(); i++){
            dp[i][i] = true;
            if(i == s.size()-1)break;
            dp[i][i+1] = s[i] == s[i+1];
        }
        for(int i = s.size()-3; i>=0; --i){
            for(int j = i+2; j < s.size(); j++){
               dp[i][j] = (dp[i+1][j-1] and s[i] == s[j]);
            }
        }
        int distance = INT_MIN;
        string result = "";
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(dp[i][j] == true and j-i+1 > distance){
                    distance = j-i+1;
                    result = s.substr(i,distance);
                }
            }
        }
        return result;
    }
};