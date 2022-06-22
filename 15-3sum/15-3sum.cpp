class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            //throw invalid_argument("num.size is less than 3");
            return vector<vector<int>>();
        }
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> results;
        
        auto i = nums.begin();
        int target = *i - 1;
        for (; i != nums.end() - 2; ++i) {
            if (*i > 0 || *i == target) { continue; }
            target = *i;
            
            // 左右双指针向中间遍历
            auto j = i + 1;
            auto k = nums.end() - 1;
            
            while (j < k) {
                if (*j + *k > -target) {
                    --k;
                    while (j < k && *k == *(k+1)) {
                        --k;
                    }
                } else if (*j + *k < -target) {
                    ++j;
                    while (j < k && *j == *(j-1)) {
                        ++j;
                    }
                } else {
                    results.push_back( vector<int>{*i, *j, *k} );
                    ++j;
                    while (j < k && *j == *(j-1)) {
                        ++j;
                    }
                    --k;
                    while (j < k && *k == *(k+1)) {
                        --k;
                    }
                }
            }
            
        }
        
        return results;
    }
};