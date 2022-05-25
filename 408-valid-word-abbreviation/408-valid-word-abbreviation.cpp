class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        while(i < word.size() and j < abbr.size()){
            if(isdigit(abbr[j])){
                if(abbr[j] == '0'){
                    return false;
                }
                int val = 0;
                while(j < abbr.size() and isdigit(abbr[j])){
                    val = (val * 10) + (abbr[j] - '0');
                    j++;
                }
                i+=val;
            }else if(word[i] != abbr[j]){
                return false;
            }else{
                i++;
                j++;
            }
        }
        if(i == word.size() and j == abbr.size()){
            return true;
        }
        return false;
    }
};