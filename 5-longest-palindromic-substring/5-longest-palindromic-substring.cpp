class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> p(n,vector<bool>(n,false));
        for(int i = 0; i < n; i++){
            p[i][i] = true;
            if(i == n-1) break;
            p[i][i+1] = (s[i] == s[i+1]);
        }
        
        for(int i = n-3; i>=0; --i){
            for(int j = i+2; j < n; j++){
                p[i][j] = (p[i+1][j-1] and s[i] == s[j]);
            }
        }
        
        int max = 0;
        string maxstr = "";
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(p[i][j] == true and j-i+1>max){
                    max = j-i+1;
                    maxstr = s.substr(i,j-i+1);
                }
            }
        }
        return maxstr;
    }
};