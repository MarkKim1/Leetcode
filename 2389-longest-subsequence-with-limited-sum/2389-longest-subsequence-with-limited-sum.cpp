class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> result;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < queries.size(); i++){
            int sum = 0;
            int count = 0;
            for(int j = 0; j < nums.size(); j++){
                sum+=nums[j];
                if(sum <= queries[i]){
                    count = max(count,j+1);
                }
            }
            result.push_back(count);
        }
        return result;
    }
};