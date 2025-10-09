class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(!set.count(n)){
            int temp = 0;
            set.insert(n);
            while(n){
                temp += pow((n % 10),2);
                n /= 10;
            }
            if(temp == 1) return true;
            n = temp;
        }
        return false;
    }
};