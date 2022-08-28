class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> graph;
        unordered_set<string> set;
        unordered_map<string,int> map;
        for(int i = 0; i < supplies.size(); i++){
            set.insert(supplies[i]);
        }
        for(auto a : recipes){
            map[a] = 0;
        }
        for(int i = 0; i < ingredients.size(); i++){
            for(int j = 0; j < ingredients[i].size(); j++){
                if(set.find(ingredients[i][j]) == set.end()){
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    map[recipes[i]]++;
                }
            }
        }
        queue<string>q;
        vector<string> result;
        for(int i = 0; i < recipes.size(); i++){
            if(map[recipes[i]] == 0){
                q.push(recipes[i]);
            }
        }
        while(!q.empty()){
            string current = q.front();
            q.pop();
            result.push_back(current);
            for(auto a : graph[current]){
                map[a]--;
                if(map[a] == 0){
                    q.push(a);
                }
            }
        }
        return result;
    }
};