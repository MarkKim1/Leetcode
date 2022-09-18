class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        int result = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            if(!st.count(temp-1)){
                result++;
                while(st.count(temp+1)){
                    result++;
                    temp+=1;
                }
                ans = max(ans,result);
            }
            result = 0;
        }
        return ans;
    }
};