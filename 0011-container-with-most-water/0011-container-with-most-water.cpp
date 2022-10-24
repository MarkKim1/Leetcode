class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int result = INT_MIN;
        while(left < right){
            if(height[left] < height[right]){
                result = max(result,(right-left) * height[left]);
                left++;
            }else{
                result = max(result,(right-left) * height[right]);
                right--;
            }
        }
        return result;
    }
};