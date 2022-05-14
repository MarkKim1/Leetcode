class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int result = 0;
        int carry = 0;
        string ans;
        while(i >= 0 || j >= 0){
            result = carry;
            if(i >= 0) result+=a[i--] -'0';
            if(j >= 0) result+=b[j--] -'0';
            carry = result > 1 ? 1 : 0;
            ans+=to_string(result%2);
        }
        if(carry) ans+=to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};