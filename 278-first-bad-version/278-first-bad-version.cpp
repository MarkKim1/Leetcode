// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
    long low = 1;
    long high = n;
    long mid;
        
        while(low < high){
            mid = (low+high) /2;
            
            if(isBadVersion(mid)){
                high = mid;
            }
            else if(isBadVersion(mid) == false){
                low = mid+1;
            }
        }
        return low;
    }
    };