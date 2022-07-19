class Solution {
public:
    //TC-O(n)
    string longestPalindrome(string s) {
        string ans = "";
        ans += s[0];
        int maxLen = 0;
        //partition between letters
        for(int i=1;i<s.size();i++){
            int j = 1, k = 0;
            while(i + k < s.size() && i - j >= 0 && s[i + k] == s[i - j]){
                if(2 * j > maxLen){
                    maxLen = 2 * j;
                    ans  = s.substr(i - j, maxLen);   
                }
                j++;
                k++;
            }
        }
        
        //letter itself as center
        for(int i=1;i<s.size();i++){
            int j = 1;
            while(i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]){
                if(2 * j + 1 > maxLen){
                    maxLen = 2 * j + 1;
                    ans = s.substr(i - j, maxLen);
                }
                j++;
            }
        }
        
        return ans;
    }
};