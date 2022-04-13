class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size();
        int mid = (left + right) /2;
            for(int i = 0; i <mid;i++){
                char temp = s[i];
                s[i] = s[right-i-1];
                s[right-i-1] = temp;
            }
    }
};