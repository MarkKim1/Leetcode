class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int pos = 1;
        vector<pair<int,int>> cells(n * n + 1);
        bool gofromright = false;
        for(int i = board.size() - 1; i >= 0; i--){
            if(gofromright){
                for(int j = board[0].size() - 1; j >= 0; j--){
                   cells[pos++] = {i,j};
                }
                gofromright = !gofromright;
            }
            else{
                for(int j = 0; j < board[0].size(); j++){
                   cells[pos++] = {i,j};
                }
                gofromright = !gofromright;
            }
        }
        queue<int> q;
        q.push(1);
        vector<int> result(n * n + 1, -1);
        result[1] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int next = curr + 1; next <= min(curr + 6, n * n); next++){
                auto [r,c] = cells[next];
                int dest = board[r][c] == -1 ? next : board[r][c];
                if(result[dest] != -1) continue;
                q.push(dest);
                result[dest] = result[curr] + 1;
            }
        }
        return result[n*n];

    }
};