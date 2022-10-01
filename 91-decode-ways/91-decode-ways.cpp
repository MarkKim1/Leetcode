class Solution {
public:
    map<int,int> memo;
    int numDecodings(string s) {
        return DFS(0,s);
    }
    int DFS(int i, string s){
        if(memo.find(i) != memo.end()){
            return memo[i];
        }
        if(s[i] == '0'){
            return 0;
        }
        if(i >= s.size()){
            return 1;
        }
        if(i == s.size()-1){
            return 1;
        }
        int ans = DFS(i+1,s);
        if(stoi(s.substr(i,2)) <= 26){
            ans += DFS(i+2,s);
        }
        memo[i] = ans;
        return ans;
    }
};