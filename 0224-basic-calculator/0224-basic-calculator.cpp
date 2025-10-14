class Solution {
public:
    int calculate(string s) {
        long long res = 0;        // current accumulated value
        int sign = 1;             // sign for the next number (+1 or -1)
        std::stack<long long> st; // stack holds: prev_res, prev_sign (pair)

        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == ' ') continue;

            if (isdigit(c)) {
                long long num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i;                    // step back one because for-loop will ++i
                res += sign * num;      // apply current sign
            } else if (c == '+') {
                sign = 1;               // unary '+' just sets sign
            } else if (c == '-') {
                sign = -1;              // unary '-' sets sign to -1
            } else if (c == '(') {
                // push context and reset for inner expression
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                int prevSign = (int)st.top(); st.pop();
                long long prevRes = st.top(); st.pop();
                res = prevRes + prevSign * res;
            }
        }
        return (int)res;
    }
};