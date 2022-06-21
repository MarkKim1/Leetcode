class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<double,int> pair;
        priority_queue<pair,vector<pair>,greater<pair>> pq;
        vector<vector<int>> result;
        
        for(int i = 0; i < points.size(); i++){
            double distance = sqrt(pow(points[i][0]-0,2) + pow(points[i][1]-0,2));
            pq.push(make_pair(distance,i));
        }
        for(int i = 0; i < k; i++){
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return result;
        
    }
};