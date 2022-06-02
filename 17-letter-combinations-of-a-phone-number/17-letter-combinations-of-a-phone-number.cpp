class Solution {
public:
    unordered_map<char,vector<char>> map = 
    {{'2',{'a','b','c'}},{'3',{'d','e','f'}},{'4',{'g','h','i'}},{'5',{'j','k','l'}},
    {'6',{'m','n','o'}},{'7',{'p','q','r','s'}},{'8',{'t','u','v'}},{'9',{'w','x','y','z'}}};
    string phoneDigits;
    int a = 0;
    vector<string> letterCombinations(string digits) {
        this->phoneDigits = digits;
        string letter = "";
        vector<string> combination;
        
        if(digits.size() == 0){
            return combination;
        }
        backTracking(0,letter,combination);
        return combination;
    }
    void backTracking(int index,string letter,vector<string>&combination){
        if(letter.length() == phoneDigits.length()){
            combination.push_back(letter);
            return;
        }
        
        vector<char> possibleLetter = map[phoneDigits[index]];
        for(char a: possibleLetter){
            letter+=a;
            backTracking(index+1,letter,combination);
            letter.pop_back();
        }
    }
};