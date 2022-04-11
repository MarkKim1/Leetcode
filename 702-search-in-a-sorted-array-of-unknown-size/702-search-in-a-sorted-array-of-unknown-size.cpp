
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        if(reader.get(0) == target){
            return 0;
        }
        int left = 0;
        int right = 1;
        while(reader.get(right) < target){
            left = right;
            right = right *2;
        }
        int pivot,mid;
        while(left <= right){
            pivot = (left + right) / 2;
            mid = reader.get(pivot);
            if(mid == target){
                return pivot;
            }
            else if(mid < target){
                left = pivot +1;
            }
            else{
                right = pivot -1;
            }
        }
        return -1;
    }
};