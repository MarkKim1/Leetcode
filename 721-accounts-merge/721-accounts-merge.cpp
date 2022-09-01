class DSU{
    public:
    vector<int> vertex;
    DSU(int x){
        for(int i = 0; i < x; i++){
          vertex.push_back(i);
        }
    }
    void uf(int a, int b){
        int rootx = find(a);
        int rooty = find(b);
        if(rootx != rooty){
            vertex[rootx] = rooty;
        }
    }
    int find(int a){
        if(vertex[a] == a){
            return a;
        }
        return find(vertex[a]);
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailgroup;
        int n = accounts.size();
        DSU dsu(n);
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                if(emailgroup.find(email) == emailgroup.end()){
                    emailgroup[email] = i;
                }else{
                    dsu.uf(i,emailgroup[email]);
                }
            }
        }
        unordered_map<int,vector<string>> components;
        for(auto it : emailgroup){
            string email = it.first;
            int index = it.second;
            components[dsu.find(index)].push_back(email);
        }
        vector<vector<string>> mergedAccounts;
        for(auto it: components){
            int group = it.first;
            vector<string> component;
            component.push_back(accounts[group][0]);
            for(auto a : components[group]){
                component.push_back(a);
            }
            sort(component.begin()+1,component.end());
            mergedAccounts.push_back(component);
        }
        return mergedAccounts;
    }
};