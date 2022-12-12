class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<int,unordered_map<int,bool>> cache;
        return dfs(s,p,0,0,cache);
        
    }
    bool dfs(string s, string p, int i, int j,unordered_map<int,unordered_map<int,bool>>& cache){
        //increment i+1 when we don't use the * 
        if(i >= s.size() and j >= p.size()) return true;
        if(j >= p.size()) return false;
        if(cache[i].find(j) != cache[i].end()){
            return cache[i][j];
        }
        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        // if there is a * in string p[j+1]
        if(j+1 < p.size() and p[j+1] == '*'){ 
            cache[i][j] = (dfs(s,p,i,j+2,cache) // don't use the * go to the next alphabet. * can not be continuous. .** => invalid a*b or .*. is valid
            || (match and dfs(s,p,i+1,j,cache))); // use the *. In order to use the * need to match s[i] and p[j] or p[j] should be '.'
            return cache[i][j];
        }
        //if p[j+1] is not a * and s[i] == p[j] or p[j] == '.' which that can be any character
        if(match){
            cache[i][j] = dfs(s,p,i+1,j+1,cache);
            return cache[i][j];
        }
        cache[i][j] = false;
        return cache[i][j];
    }
};