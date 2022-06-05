class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        int value,row,col;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < min(m,k); i++){
            pq.push({matrix[i][0],i,0});
        }
        for(int i = 0; i < k; i++){
            auto top = pq.top(); pq.pop();
            value = top[0];
            row = top[1];
            col = top[2];
            if(col+1 < n) pq.push({matrix[row][col+1],row,col+1});
        }
        return value;
    }
};