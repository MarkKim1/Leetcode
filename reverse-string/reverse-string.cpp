class Solution {
    private:
    void helper(vector<char>&s, int left, int right){
        if(left >= right){
            return;
        }
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        helper(s,++left,--right);
    }
    
    public:
    void reverseString(vector<char>& s) {
        helper(s,0,s.size()-1);
    }
};