class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Copy(m+n);
        for(int i = 0; i < nums1.size(); i++){
            nums1Copy[i] = nums1[i];
        }
        int i = 0;
        int j = 0;
        int k = 0;
        while(k <= m+n-1 && !(nums2.empty())){
            if(j > nums2.size()-1){
                nums1Copy[k++] = nums1[i++];
            }
            else if(nums1[i] <= nums2[j] && i <= m-1){
                nums1Copy[k++] = nums1[i++];
            }else{
                nums1Copy[k++] = nums2[j++];
            }
        }
        nums1 = nums1Copy;
    }
};