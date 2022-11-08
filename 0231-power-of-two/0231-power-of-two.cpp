class Solution {
public:
    bool isPowerOfTwo(int n) {
        long x = n;
        return (x && !(x & (x-1)));
    }
};