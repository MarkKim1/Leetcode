class Solution {
public:
    bool detectCapitalUse(string word) {
        int isAllCapital = 0;
        for(int i = 0; i < word.size(); i++){
            if(isupper(word[i])){
                isAllCapital++;
            }
        }
        if(isAllCapital == word.size() || isAllCapital == 0){
            return true;
        }
        if(isAllCapital == 1 and isupper(word[0])){
            return true;
        }
        return false;
    }
};