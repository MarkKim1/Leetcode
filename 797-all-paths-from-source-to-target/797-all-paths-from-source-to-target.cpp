class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = int(graph.size()) - 1;
        map<int, vector<vector<int>>> memo;
        function<vector<vector<int>>(int)> allPathsToTarget = [&](int currNode) {
            if (memo.count(currNode)) return memo[currNode];
            vector<vector<int>> results;
            if (currNode == target) {
                results.push_back(vector<int>{target});
            } else {
                for (int nextNode : graph[currNode]) {
                    for (vector<int>& path : allPathsToTarget(nextNode)) {
                        vector<int> newPath{currNode};
                        newPath.insert(newPath.end(), path.begin(), path.end());
                        results.push_back(newPath);
                    }
                }
            }
            memo[currNode] = results;
            return results;
        };
        return allPathsToTarget(0);
    }
};