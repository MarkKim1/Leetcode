class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> result;
        for(int a: nums2){
            if(m.erase(a) > 0){
                result.push_back(a);
            }
        }
        return result;
    }
};