class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects;
        
        for(int i = 0; i < n; i++){
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxprofit;
        int i = 0;
        while(k--){
            for(;i < n and projects[i].first <= w; i++){
                maxprofit.push(projects[i].second);
            }
            if(maxprofit.empty()) break;
            w += maxprofit.top();
            maxprofit.pop();
        }
        return w;
    }
};