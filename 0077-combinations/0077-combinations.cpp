class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        helper(n,k,1,{});
        return result;
    }
    void helper(int n, int k, int i, vector<int> curr){
        for(int pos = i; pos <= n; pos++){
            curr.push_back(pos);
            if(curr.size() == k){
                result.push_back(curr);
            }
            helper(n,k,pos + 1,curr);
            curr.pop_back();
        }
    }
};