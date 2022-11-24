class Solution {
public:
    bool isStrobogrammatic(string num) {
        string strobo = "";
        for(int i = num.size()-1; i >= 0; i--){
            if(num[i] != '6' && num[i] != '9' && num[i] != '8' && num[i] != '0' && num[i] != '1'){
                return false;
            }
            if(num[i] == '6'){
                strobo.push_back('9');
            }else if(num[i] == '9'){
                strobo.push_back('6');
            }else{
                strobo.push_back(num[i]);
            }
        }
        return strobo == num;
    }
};