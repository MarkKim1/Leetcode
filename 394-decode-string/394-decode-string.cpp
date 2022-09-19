class Solution {
public:
    string result;
    string decodeString(string s) {
        string temp = "";
        string num;
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                num+=s[i];
                s[i] = '@';
            }else if(isalpha(s[i])){
                result+=s[i];
            }else if(s[i] == '['){
                s[i] = '@';
                helper(stoi(num),s,i,temp);
                num = "";
            }
            result+=temp;
            temp = "";
        }
        return result;
    }
        void helper(int num, string& partial,int j,string& temp){
            string a = "";
            string num1 = "";
            for(int i = j; i < partial.size(); i++){
                if(isdigit(partial[i])){
                    num1+=partial[i];
                    partial[i] = '@';
                }
                if(partial[i] == ']'){
                    partial[i] = '@';
                    for(int i = 0; i < num; i++){
                        temp+=a;
                    }
                    return;
                }
                if(partial[i] == '['){
                    partial[i] = '@';
                    helper(stoi(num1),partial,i,temp);
                    a+=temp;
                    temp = "";
                    num1 = "";
                }
                if(partial[i] != '@'){
                    a+=partial[i];
                    partial[i] ='@';
                }
            }
        }
};