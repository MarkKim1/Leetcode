class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<>>> map;
    vector<string> result;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        
        for(int i = 0; i < tickets.size(); i++){
            string from = tickets[i][0];
            string to = tickets[i][1];
            map[from].push(to);
        }
        
        string temp = "JFK";
        dfs(temp);
        reverse(result.begin(),result.end());
        return result;
    }
    void dfs(string temp){
        
        while(!map[temp].empty()){
            string temp1 = map[temp].top();
            map[temp].pop();
            dfs(temp1);
        }
        result.push_back(temp);
        
    }
};