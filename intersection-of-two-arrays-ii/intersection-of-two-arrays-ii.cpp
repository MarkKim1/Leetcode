class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() > nums1.size()){
            return intersect(nums2,nums1);
        }
        unordered_map<int,int> map;
        for(auto n: nums1){
          map[n]++;
        }
        int k = 0;
        for(auto c: nums2){
            auto it = map.find(c);
            if(it != map.end() && --it->second >=0){
                nums1[k++] = c;
            }
        }
        return vector(nums1.begin(),nums1.begin() + k);
        
    }
};