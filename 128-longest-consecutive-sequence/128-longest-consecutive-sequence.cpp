class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> num_set;
        int longest_streak =0;
        int streak = 1;
        for(int i = 0; i< nums.size(); i++){
            num_set.insert(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            if(!num_set.count(nums[i]-1)){
                int new_num = nums[i];
                while(num_set.count(new_num+1)){
                    streak++;
                    new_num = new_num+1;
                }
            longest_streak = max(longest_streak,streak);
            streak = 1;
            }
        }
        return longest_streak;
    }
};