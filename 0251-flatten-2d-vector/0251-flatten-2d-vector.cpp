class Vector2D {
public:
    vector<vector<int>> ans;
    int row = 0;
    int col = 0;
    Vector2D(vector<vector<int>>& vec) {
        ans = vec;
    }
    
    int next() {
        hasNext();
        return ans[row][col++];
    }
    
    bool hasNext() {
        while(row < ans.size() and col == ans[row].size()){
            row++;
            col = 0;
        }
        return row != ans.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */