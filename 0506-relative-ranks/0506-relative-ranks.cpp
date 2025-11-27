class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> result(score.size(), "");
        auto comp = [&](pair<int,int>& a, pair<int,int>& b){
            return a.first < b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> maxheap(comp);
        for(int i = 0; i < score.size(); i++){
            maxheap.push(make_pair(score[i], i));
        }
        int count = 1;
        while(!maxheap.empty()){
            if(count <= 3){
                auto curr = maxheap.top();
                if(count == 1){
                    result[curr.second] = "Gold Medal";
                }
                else if(count == 2){
                    result[curr.second] = "Silver Medal";
                }
                else{
                    result[curr.second] = "Bronze Medal";
                }
            }
            else{
                result[maxheap.top().second] = to_string(count);
            }
            maxheap.pop();
            count++;    
        }
        return result;
    }
};