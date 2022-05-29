class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int one = num1.size()-1;
        int two = num2.size()-1;
        int carry = 0;
        while(one >= 0 || two >= 0){
            int first = one >= 0 ? num1[one] - '0' : 0;
            int second = two >= 0 ? num2[two] - '0' : 0;
            result +=to_string((first + second + carry) % 10);
            carry = (first+second + carry) / 10;
            one--;
            two--;
        }
        if(carry == 1){
            result+=to_string(carry);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};