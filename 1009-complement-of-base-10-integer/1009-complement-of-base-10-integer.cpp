class Solution {
public:
    int bitwiseComplement(int n) {
        int comp = 1;
        while(comp < n){
            comp = (comp<<1) | 1;
        }
        return n ^comp;
    }
};