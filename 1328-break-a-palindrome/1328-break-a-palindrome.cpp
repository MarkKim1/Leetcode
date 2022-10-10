class Solution {
public:
    string breakPalindrome(string p) {
        int left = 0;
        int right = p.size()-1;
        if(p.size() == 1) return "";
        vector<string> result;
        while(left < right){
            string source = p;
            if(source[left] == 'a' and source[right] == 'a'){
                source[right] = 'b';
            }else if(source[left] == 'z' and source[right] == 'z'){
                source[left] = 'a';
            }else{
                source[left] = 'a';
            }
            result.push_back(source);
            left++;
            right--;
        }
        sort(result.begin(),result.end());
        return result[0];
    }
};