class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        vector<int> squares;
        squares.push_back(1);
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int square_index = i * i;
            if(square_index <= n){
                dp[square_index] = 1;
                squares.push_back(square_index);
            }
            if(dp[i] != 0){
                continue;
            }
            if(i > 3){
                int curr = dp[i-squares[0]] + dp[i - (i-squares[0])];
                for(int j = 0; j < squares.size(); j++){
                    if(i-squares[j] > 0){
                        curr = min(curr,dp[i-squares[j]] + 1);
                    }else{
                        break;
                    }
                }
                dp[i] = curr;
            }else{
                dp[i] = dp[i-1] + 1;
            }
        }
        return dp[n];
    }
};