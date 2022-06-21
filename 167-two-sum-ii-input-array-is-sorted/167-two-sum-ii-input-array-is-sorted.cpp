class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        vector<int> result;
        
        
        while(left < right){
            if(numbers[left] + numbers[right] == target){
                result = {left+1,right+1};
                break;
            }
            
            else if(numbers[left] + numbers[right] > target){
                right--;
            }
            else if(numbers[left] + numbers[right] < target){
                left++;
            }
        }
        return result;
    }
};