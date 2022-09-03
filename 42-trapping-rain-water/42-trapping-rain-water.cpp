class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftmax = height[left];
        int rightmax = height[right];
        int res = 0;
        while(left < right){
            if(height[left] > height[right]){
                right-=1;
                if(height[right] > rightmax){
                    rightmax = height[right];
                    continue;
                }
                res += rightmax-height[right];
            }else{
                left+=1;
                if(height[left] > leftmax){
                    leftmax = height[left];
                    continue;
                }
                res += leftmax-height[left];
            }
        }
        return res;
    }
};