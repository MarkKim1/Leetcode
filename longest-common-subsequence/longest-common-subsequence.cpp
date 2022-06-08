class Solution {
public:
    string text1;
    string text2;
    int answer;
    int memo[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        this->text1 = text1;
        this->text2 = text2;
        
        for (int i = 0; i < text1.length(); i++) {
            for (int j = 0; j < text2.length(); j++) {
                this->memo[i][j] = -1;
            }
        }
        this->answer = 0;
        return dp(0,0);
    }
    int dp(int p1,int p2){
        if(memo[p1][p2] != -1){
            return memo[p1][p2];
        }
        if(text1[p1] == text2[p2]){
            answer = 1 + dp(p1+1,p2+1);
        }
        else{
            answer = max(dp(p1,p2+1),dp(p1+1,p2));
        }
        
        memo[p1][p2] = answer;
        return memo[p1][p2];
    }
};