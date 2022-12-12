class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<int,unordered_map<int,bool>> cache;
        return dfs(s,p,0,0,cache);
        
    }
    bool dfs(string s, string p, int i, int j,unordered_map<int,unordered_map<int,bool>>& cache){
        if(i >= s.size() and j >= p.size()) return true;
        if(j >= p.size()) return false;
        if(cache[i].find(j) != cache[i].end()){
            return cache[i][j];
        }
        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if(j+1 < p.size() and p[j+1] == '*'){ // if there is a * in string p
            cache[i][j] = (dfs(s,p,i,j+2,cache) // don't use the *
            || (match and dfs(s,p,i+1,j,cache))); // use the * in order to use the * need to match s[i] and p[j]
            return cache[i][j];
        }
        //there is no star in string p;
        if(match){
            cache[i][j] = dfs(s,p,i+1,j+1,cache);
            return cache[i][j];
        }
        cache[i][j] = false;
        return cache[i][j];
    }
};