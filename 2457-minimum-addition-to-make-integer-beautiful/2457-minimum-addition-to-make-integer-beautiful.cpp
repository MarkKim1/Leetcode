class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long temp = n;
        long long count = 1;
        while(sum(temp) > target){
            temp = (temp / 10) + 1;
            count*=10;
        }
        return temp * count - n;
    }
private:
    int sum(long long n){
        long long curr = 0;
        while(n != 0){
            curr = curr + (n %10);
            n /= 10;
        }
        return curr;
    }
};