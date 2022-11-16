class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++){
            string a = to_string(i);
            reverse(a.begin(),a.end());
            int b = stoi(a);
            if(i + b == num) return true; 
        }
        return false;
    }
};