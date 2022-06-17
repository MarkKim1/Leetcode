class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            //odd-length palindromes, single character center
            ans+=is_palindrome(s,i,i);
            //even-length palindromes, consecutive character center
            ans+=is_palindrome(s,i,i+1);
        }
        return ans;
    }
    int is_palindrome(const string& s,int low,int high){
        int ans = 0;
        while(low >= 0 and high < s.size()){
            if(s[low] != s[high]){
                break;
            }
            low--;
            high++;
            ans++;
        }
        return ans;
    }
};