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
    //this solution has space complextiy of O(1) since we are not allocating any extra space to find substring
    // time complexity is O(N^2)
    //1. The number of possible palindromic centers we process
    //2. How much time we spend processing each center
};