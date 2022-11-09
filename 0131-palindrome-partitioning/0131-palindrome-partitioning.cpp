class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;
    vector<vector<string>> partition(string s) {
        DFS(s,0);
        return ans;
    }
    void DFS(string s, int start){
        if(start >= s.length()){
            ans.push_back(curr);
        }
        for(int end = start; end < s.length(); end++){
            if(ispalindrome(s,start,end)){
                curr.push_back(s.substr(start,end-start+1));
                DFS(s,end+1);
                curr.pop_back();
            }
        }
    }
    bool ispalindrome(string s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
};