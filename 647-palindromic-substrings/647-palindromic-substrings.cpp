class Solution {
public:
    int countSubstrings(string s) {
        //there are two base cases
        //1. when s is single character
        //2. when s is double letter string
        
        if(s.size() == 0) return 0;
        
        int n = s.size();
        int ans = 0;
        bool dp[n][n];
        fill_n(*dp,n*n,false);
        
        //1. when s is single character
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            ans++;
        }
        //2. when s is double letter string
        for(int i = 0; i <n-1; i++){
            dp[i][i+1] = s[i] == s[i+1];
            ans+=dp[i][i+1];
        }
        
        //for string from 3 to n
        for(int len = 3; len <= n; len++){
            for(int i = 0,j = i+len-1;j<n;i++,j++){
                dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};