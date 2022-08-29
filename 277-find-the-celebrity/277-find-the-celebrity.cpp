/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        for(int i = 0; i < n; i++){
            if(isCelebrity(i,n)){
                return i;
            }
        }
        return -1;
    }
    bool isCelebrity(int i,int n){
        for(int j = 0; j <n; j++){
            if(i == j) continue;
            if(knows(i,j) or knows(j,i) == false){
                return false;
            }
        }
        return true;
    }
};