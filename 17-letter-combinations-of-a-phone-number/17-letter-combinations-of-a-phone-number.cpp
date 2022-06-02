class Solution {
public:
    unordered_map<char,vector<char>> map = 
    {{'2',{'a','b','c'}},{'3',{'d','e','f'}},{'4',{'g','h','i'}},{'5',{'j','k','l'}},
    {'6',{'m','n','o'}},{'7',{'p','q','r','s'}},{'8',{'t','u','v'}},{'9',{'w','x','y','z'}}};
    vector<string> combination;
    string phoneDigits;
    int a = 0;
    vector<string> letterCombinations(string digits) {
        
        this->phoneDigits = digits;
        string letter = "";
        
        if(digits.size() == 0){
            return combination;
        }
        
        backTracking(0,letter);
        return combination;
    }
    void backTracking(int index,string letter){
        if(letter.length() == phoneDigits.length()){
            combination.push_back(letter);
            return;
        }
        vector<char> possibleLetters = map[phoneDigits[index]];
        for(char a: possibleLetters){
            letter+=a;
            backTracking(index+1,letter);
            letter.pop_back();
        }
    }
};