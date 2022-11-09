class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        DFS(ans,curr,s,0);
        return ans;
    }
    void DFS(vector<vector<string>>& ans, vector<string>& curr, string s, int start){
        if(start >= s.size()){
            ans.push_back(curr);
        }
        for(int end = start; end < s.size(); end++){
            if(isPalindrome(s,start,end)){
                curr.push_back(s.substr(start,end-start+1));
                DFS(ans,curr,s,end+1);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
};