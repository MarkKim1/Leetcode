class UnionFind {
public:
    vector<int> vec;
    vector<int> rank;
    UnionFind(int n){
        for(int i = 0; i < n + 1; i++){
            vec.push_back(i);
            rank.push_back(1);
        }
    }
    int find(int n){
        if(n == vec[n]){
            return n;
        }
        return vec[n] = find(vec[n]);
    }
    void Union(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            vec[rootx] = rooty;
            rank[rooty] += rank[rootx];
        }
    }

};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int,int> map;
        int result = 0;
        UnionFind *un = new UnionFind(nums.size());
        
        for(int i = 0; i < nums.size(); i++){
            if(map.count(nums[i])) continue;
            if(map.count(nums[i] + 1)){
                un->Union(i,map[nums[i] + 1]);
            }
            if(map.count(nums[i] - 1)){
                un->Union(i,map[nums[i] - 1]);
            }
            map[nums[i]] = i;
        }
        for(int i = 0; i < un->vec.size(); i++){
            if(un->vec[i] == i){
                result = max(result,un->rank[i]);
            }
        }     
        return result;
    }
};