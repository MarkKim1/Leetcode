class Solution {
public:
    int reverse(int x) {
        int temp = abs(x);
        int ans = 0;
        while(temp != 0){
            int num = temp%10;
            if(num == 0){
                ans = ans*10;
            }else{
                if(ans > INT_MAX/10 || (ans == INT_MAX/10 and num > 7)) return 0;
                if(ans < INT_MIN/10 || (ans == INT_MIN/10 and num < -8)) return 0;
                ans = ans*10 + num;
            }
            temp /=10;
        }
        return x < 0 ? -ans : ans;
    }
};
