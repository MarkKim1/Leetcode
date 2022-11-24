class Solution {
public:
    bool isStrobogrammatic(string num) {
        string strobo = "";
        for(int i = num.size()-1; i >= 0; i--){
            if(num[i] != '6' && num[i] != '9' && num[i] != '8' && num[i] != '0' && num[i] != '1'){
                return false;
            }
            if(num[i] == '6'){
                if(num[num.size()-i-1] != '9'){
                    return false;
                }
            }else if(num[i] == '9'){
                 if(num[num.size()-i-1] != '6'){
                    return false;
                }
            }else{
                if(num[num.size() -i-1] != num[i]){
                    return false;
                }
            }
        }
        return true;
    }
};