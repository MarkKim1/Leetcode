class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
    auto rev = [](int n) {
        int rn = 0;
        for (; n; n /= 10)
            rn = rn * 10 + n % 10;
        return rn;
    };  
    for (int n1 = num / 2; n1 <= num; ++n1)
        if (n1 + rev(n1) == num)
            return true;
    return false;
}
};