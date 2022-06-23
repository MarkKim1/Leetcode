class Solution {
    public:
     vector<int> root;
    vector<int> rank;
    int count;
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 0) {
            return 0;
        }
        this->count = isConnected.size();
        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            root.push_back(i);
            rank.push_back(1);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    unionSet(i, j, n);
                }
            }
        }
        return getCount();
    }
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y,int n) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }

    int getCount() {
        return count;
    }

};