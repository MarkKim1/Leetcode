class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        typedef pair<int,int> pair;
        priority_queue<pair,vector<pair>,greater<pair>> pq;
        vector<int> ans;
        int protect = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 1){
                    protect++;
                }
            }
            pq.push(make_pair(protect,i));
            protect = 0;
        }
        for(int i =0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};