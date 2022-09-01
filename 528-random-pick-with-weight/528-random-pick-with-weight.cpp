class Solution {
public:
    vector<int> a;
    Solution(vector<int>& w) {
        for(int v : w){
            a.push_back(v + (a.empty() ? 0 :a.back()));
        }
    }
    
    int pickIndex() {
        float rand_number = (float)rand() / RAND_MAX;
        float target = rand_number * a.back();
        for(int i = 0; i < a.size(); i++){
            if(target < a[i]){
                return i;
            }
        }
        return a.size()-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */