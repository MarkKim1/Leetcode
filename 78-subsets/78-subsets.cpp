class Solution {
public:
    vector<vector<int>> result;
    vector<int> sub;
    int other = 0;
    vector<vector<int>> subsets(vector<int>& nums) {
        //result.push_back(sub);
        find(nums,0);
        return result;
    }
    
    void find(vector<int>&nums, int i){
        result.push_back(sub);   
        for(int j = i; j < nums.size(); j++){
            sub.push_back(nums[j]);
            find(nums,j+1);
            sub.pop_back();
            }
        }
};

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> subs;
//         vector<int> sub;
//         subsets(nums, 0, sub, subs);
//         return subs;
//     }
// private:
//     void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
//         subs.push_back(sub);
//         for (int j = i; j < nums.size(); j++) {
//             sub.push_back(nums[j]);
//             subsets(nums, j + 1, sub, subs);
//             sub.pop_back();
//         }
//     }
// };