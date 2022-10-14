class DSU {
    public:
    vector<int> root;
    DSU (int x) {
      for(int i = 0; i < x; i++){
          root.push_back(i);
      }
    }  
    
    void Union(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            root[rooty] = rootx;
        }
    }
    int find(int x){
        if(root[x] == x){
            return x;
        }
        return root[x] = find(root[x]);
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> map;
        int n = accounts.size();
        DSU dsu(n);
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                if(map.find(email) == map.end()){
                    map[email] = i;
                }else{
                    dsu.Union(i,map[email]);
                }
            }
        }
        unordered_map<int,vector<string>> getEmails;
        for(auto list: map){
            string email = list.first;
            int index = list.second;
            getEmails[dsu.find(index)].push_back(email);
        }
        vector<vector<string>> result;
        for(auto list: getEmails){
            int owner = list.first;
            vector<string> a = list.second;
            vector<string> sub;
            sub.push_back(accounts[owner][0]);
            sort(a.begin(),a.end());
            sub.insert(sub.end(),a.begin(),a.end());
            result.push_back(sub);
        }
        return result;
    }
};