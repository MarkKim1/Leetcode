class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int result = 0;
        queue<pair<string,int>> q;
        unordered_set<string> set;
        
        q.push({startGene,0});
        set.insert(startGene);
        
        while(!q.empty()){
            auto curr = q.front();
            if(curr.first == endGene) return curr.second;
            q.pop();
            for(string each : bank){
                int diff = 0;
                if(set.count(each)) continue;
                for(int i = 0; i < curr.first.size(); i++){
                    if(curr.first[i] != each[i]) diff++;
                }
                if(diff == 1){
                    set.insert(each);
                    q.push({each,curr.second + 1});
                }
            }
        }
        return -1;
    }
};