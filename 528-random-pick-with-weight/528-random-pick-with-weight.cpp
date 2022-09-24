class Solution {
public:
    vector<int> v;
    Solution(vector<int>& w) {
        for(int i = 0; i < w.size(); i++){
            v.push_back(w[i] + (v.empty() ? 0 : v.back()));
        }
    }
    
    int pickIndex() {
        float random = (float)rand() / RAND_MAX;
        float a = random * v.back();
        for(int i = 0; i < v.size(); i++){
            if(a < v[i]){
                return i;
            }
        }
        return v.size()-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */