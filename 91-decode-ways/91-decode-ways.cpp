class Solution {
public:
    unordered_map<int,int> map;
    int numDecodings(string s) {
        return recursiveWithMemo(0,s);
    }
    int recursiveWithMemo(int i, string s){
        if(i == s.size()) return 1;
        
        if(map.find(i) != map.end()){
            return map[i];
        }
        if(s[i] == '0'){
            return 0;
        }
        if(i == s.size()-1){
            return 1;
        }
        int ans = recursiveWithMemo(i+1,s);
        if(stoi(s.substr(i,2)) <= 26){
            ans+=recursiveWithMemo(i+2,s);
        }
        map[i] = ans;
        return ans;
    }
};