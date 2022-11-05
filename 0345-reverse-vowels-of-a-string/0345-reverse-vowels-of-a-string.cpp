class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            while(left < s.size() and !isVowel(s[left])){
                left++;
            }
            while(right >= 0 and !isVowel(s[right])) {
                right--;
            }
            if(left < right){
                swap(s[left++],s[right--]);
            }
        }
        return s;
    }
    bool isVowel(char s){
        return s == 'A' || s =='E' || s == 'I' || s == 'O' || s == 'U' ||
            s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
    }
};