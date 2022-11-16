class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        auto rev = [](int i){
            int result = 0;
            while(i != 0){
                result = result * 10 + i % 10;
                i /= 10;
            }
            return result;
        };
        for(int i = num/2; i <= num; i++){
            if(i + rev(i) == num) return true;
        }
        return false;
    }
};