class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        if(k == arr.size()){
            for(int i = 0; i < arr.size(); i++){
                result.push_back(arr[i]);
            }
            return result;
        }
        int left = 0;
        int right = arr.size();
        int mid = 0;
        //find 
        while(left < right){
            mid = (left + right) / 2;
            if(arr[mid] > x){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        left--;
        right = left+1;
        while(right-left-1 < k){
            if(left == -1){
                right+=1;
                continue;
            }
            if(right == arr.size() || abs(arr[left]-x) <= abs(arr[right]-x)){
                left--;
            }else{
                right++;
            }
        }
        for(int i = left+1; i < right; i++){
            result.push_back(arr[i]);
        }
        
        return result;
    }
};