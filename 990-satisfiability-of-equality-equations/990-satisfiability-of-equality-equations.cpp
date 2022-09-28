class Solution {
public:
    bool equationsPossible(vector<string>& es) {
        vector<int> root(26);
        iota(root.begin(),root.end(),0);
        
        function<int(int)> find = [&](int x){
            if(root[x] == x){
                return x;
            }
            return root[x] = find(root[x]);
        };
        
        auto unionSet = [&](int a, int b){
            int rootx = find(a);
            int rooty = find(b);
            root[rooty] = rootx;
        };
        for(auto e: es){
            if(e[1] == '='){
                unionSet(e[0]-'a',e[3]-'a');
            }
        }
        for(auto e: es){
            if(e[1] == '!'){
                if(find(e[0]-'a') == find(e[3]-'a')){
                    return false;
                }
            }
        }
        return true;
    }
};