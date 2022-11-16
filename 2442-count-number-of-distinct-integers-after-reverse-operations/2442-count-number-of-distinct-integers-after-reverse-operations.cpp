class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        vector<int> sub;
        int size = nums.size();
        unordered_set<int> set;
        for(int i = 0; i < size; i++){
            set.insert(nums[i]);
            string a = to_string(nums[i]);
            reverse(a.begin(),a.end());
            int b = stoi(a);
            set.insert(b);
        }
        return set.size();
    }
};