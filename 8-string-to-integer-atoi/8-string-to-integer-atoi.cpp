class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int to_compute = 1;
        if(s == "0") return 0;
        if(s[0] == '.')return 0;
        int error = 0;
        int zero_count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]-'0' == 0){
                zero_count++;
            }
            if(s[i] == ' '){
                if(result != 0) return result;
                if(error > 0 and result == 0) return 0;
                if(zero_count > 0 and result == 0) return 0;
                continue;
            }
            //if(s[i] == '0' and result == 0) continue; 
            if(result != 0 and (s[i] == '-' or s[i] == '+' or s[i] =='.')){
                return result;
            }
            if(s[i] == '-'){
                to_compute = -to_compute;
                error++;
                if(zero_count > 0) return 0;
                if(error == 2) return 0;
            }
            if(s[i] == '+'){
                error++;
                if(error == 2) return 0;
            }
            if(isalpha(s[i])){
                return result;
            }
            if(s[i]-'0' >= 0 and s[i]-'0' <= 9){
                if(result > INT_MAX/10 || (result == INT_MAX/10 and (s[i]-'0') > INT_MAX%10)){
                    return INT_MAX;
                }
                if(result < INT_MIN/10 || (result == INT_MIN/10 and -(s[i]-'0') < INT_MIN%10)){
                    return INT_MIN;
                }
                result = result * 10 + (s[i]-'0') * to_compute;
            }
        }
        return result;
    }
};