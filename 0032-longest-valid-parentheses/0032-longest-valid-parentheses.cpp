class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> longest(s.size(),0);
        int ans = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    longest[i] = i - 2 >= 0 ? longest[i-2] + 2 : 2; 
                    ans = max(ans,longest[i]);
                }else{
                    if(i-longest[i-1]-1 >= 0 and s[i-longest[i-1]-1] == '('){
                        longest[i] = longest[i-1] + 2 + (i-longest[i-1]-2 >= 0 and s[i-longest[i-1]-2] == ')' ? longest[i-longest[i-1]-2] : 0);
                        ans = max(ans,longest[i]);
                    }
                }
            }
        }
        return ans;
    }
};