class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i])){
                result+=tolower(s[i]);
            }
            if(isdigit(s[i])){
                result+=s[i];
            }
        }
        cout << result;
        string ans = result;
        reverse(ans.begin(),ans.end());
        if(ans == result){
            return true;
        }
        return false;
    }
};