class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0]; 
        sort(nums.begin(),nums.end());
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]+=nums[i];
        }
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int one = 0;
        int two = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 and nums[i-1]+1 == nums[i]){
                int temp = one;
                one = max(two + map[nums[i]],one);
                two = temp;
            }else{
                int temp = one;
                one = one + map[nums[i]];
                two = temp;
            }
        }
        return one;
    }
};

// class Solution {
// public:
//     int deleteAndEarn(vector<int>& nums) {
//         if(nums.size() == 1) return nums[0];
//         sort(nums.begin(),nums.end());
//         unordered_map<int,int> map;
//         int one = 0,two = 0;
//         for(int i = 0; i < nums.size(); i++){
//             map[nums[i]]+=nums[i];
//         }
        
//         nums.erase(unique(nums.begin(),nums.end()),nums.end());
        
//         for(int i = 0; i < nums.size(); i++){
//             if(i > 0 and nums[i] == nums[i-1]+1){
//                 int temp = two;
//                 two = max(map[nums[i]]+one,two);
//                 one = temp;
//             }else{
//                 int temp = two;
//                 two = map[nums[i]] + two;
//                 one = temp;
//             }
//         }
        
//         return two;
//     }
// };