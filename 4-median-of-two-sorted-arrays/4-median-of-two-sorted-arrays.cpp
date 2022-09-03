class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        vector<int> num;
        int count1 = 0;
        int count2 = 0;
        while(true){
            if(count2 == nums2.size()){
                for(int i = count1; i <nums1.size();i++)
                    num.push_back(nums1[i]);
                break;
            }
            if(count1 == nums1.size()){
                for(int i = count2; i < nums2.size(); i++)
                    num.push_back(nums2[i]);
                break;
            }
            if(nums1[count1] <= nums2[count2]){
                num.push_back(nums1[count1++]);
            }else{
                num.push_back(nums2[count2++]);
            }
        }
        int n = num.size();
        if(n%2 != 0){
            int a = num.size()/2;
            return (double)num[a];
        }else{
            int b = num.size()/2;
            return (double)(num[b] + num[b-1]) / 2;
        }
        
    }
};