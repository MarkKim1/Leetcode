class Solution {
public:
    bool isUgly(int n) {
        if(n == 0) return false;
        if(n == 1)return true;
        return divide(n,n);
    }
    bool divide(int n,int source){
        if(n == 2 || n == 3 || n == 5){
            return true;
        }
        for(auto denominator: {2,3,5}){
            
            if(n % denominator == 0 and divide(n/denominator,source)){
                return true;
            }
        }
        return false;
    }
};