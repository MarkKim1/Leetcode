class Solution {
public:
    
    vector<int> sortByBits(vector<int>& arr) {
        auto comparator = [](int a, int b){
            int acount = 0;
            int bcount = 0;
            int tempa = a;
            int tempb = b;
            while(a){
                a = (a & (a-1));
                acount++;
            }
            while(b){
                b = (b & (b-1));
                bcount++;
            }
            if(acount == bcount){
                return tempa < tempb;
            }
            return acount < bcount;
        };
        
        sort(arr.begin(),arr.end(),comparator);
        return arr;
    }
};