class Solution {
public:
    
    vector<int> sortByBits(vector<int>& arr) {
        auto comparator = [](int a, int b){
            bitset<32> aBit(a);
            bitset<32> bBit(b);
            int acount = aBit.count();
            int bcount = bBit.count();
            if(acount == bcount){
                return a < b;
            }else{
                return acount < bcount;
            }
        };
        sort(arr.begin(),arr.end(),comparator);
        return arr;
    }
};