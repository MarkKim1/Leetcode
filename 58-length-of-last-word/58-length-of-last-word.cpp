class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<int> result;
        int length = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                length++;
                if(i == s.size()-1){
                    result.push_back(length);
                    break;
                }
            }else{
                if(length > 0){
                    cout << length;
                    result.push_back(length);
                    length = 0;
                }
            }
        }
        return result.back();
    }
};