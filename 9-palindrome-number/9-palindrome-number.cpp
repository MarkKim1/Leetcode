class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        vector<int> a;
        int per;
        while(x > 0){
            a.push_back(x%10);
            x = x/10;
        }
        int low = 0;
        int high = a.size()-1;
        while(low < high){
            if(a[low] == a[high]){
                low++;
                high--;
            }
            else{
                return false;
            }
        }
        return true; 
    }
};