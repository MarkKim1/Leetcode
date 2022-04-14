class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        char a;
        string a1;
        string a2;
        while(x > 0){
            a = (x%10) + '0';
            a1 +=a;
            x /= 10;
        }
        a2 = a1;
      reverse(a1.begin(), a1.end());
        if(a1 == a2){
            return true;
        }
        else{
            return false;
        }
    }
};