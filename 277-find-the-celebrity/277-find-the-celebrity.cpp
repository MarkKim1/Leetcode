/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int start = 0;
        for(int i = 1; i < n; i++){
            if(knows(start,i)){
                start = i;
            }
        }
        if(isCelebrity(start,n)){
            return start;
        }
        return -1;
    }
    bool isCelebrity(int i, int n){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(knows(i,j) || !knows(j,i)){
                return false;
            }
        }
        return true;
    }
};