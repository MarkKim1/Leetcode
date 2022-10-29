class Solution {
public:
    int myAtoi(string s) {
        string strAns = "";
        int ans = 0;
        int isNegative = 1;
        bool isPositive = false;
        for(int i = 0; i < s.size(); i++){
            if(strAns.empty() and (isalpha(s[i]) or s[i] == '.')){
                return 0;
            }
            //1. Read in and ignore any leading white space
            if(!strAns.empty() and !isdigit(s[i])){
                break;
            }
            if(strAns.empty() and (s[i] == ' ')){
                if(isNegative == -1 or isPositive){
                    return 0;
                }
                continue;
            }
            if(strAns.empty()){
                if(s[i] == '-'){
                    if(isPositive){
                        break;
                    }else{
                        if(isNegative == -1){
                            return 0;
                        }
                        isNegative = -1;
                    }
                }else if(s[i] == '+'){
                    if(isNegative == -1){
                        break;
                    }else{
                        if(isPositive){
                            return 0;
                        }
                        isPositive = true;
                    }
                }   
            }
            if(isdigit(s[i])){
                strAns.push_back(s[i]);
            }
        }
        for(int i = 0; i < strAns.size(); i++){
            //Value of INT_MAX is +2147483647.214748364
            //Value of INT_MIN is -2147483648.
            if((ans > INT_MAX/10) || (ans == INT_MAX/10 and strAns[i]-'0' > INT_MAX%10)){
                return isNegative == -1 ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + (strAns[i]-'0');
        }
        return isNegative * ans;
    }
};