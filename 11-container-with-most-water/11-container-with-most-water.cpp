class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max = 0;
        while(left<=right){
            int start = height[left]; // 1
            int end = height[right]; // 2
            if(start < end){
                //if height[left] is less than height[right]
                if(max < start * (right-left)){
                    max = start * (right-left);
                }
                left++;
            }
            else{
                if(max < end * (right-left)){
                    max = end * (right-left);
                }
                right--;
            }
        }
        return max;
    }
};