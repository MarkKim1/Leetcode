class Solution {
public:
    vector<string> result;
    unordered_map<char,vector<char>> map;
    vector<string> letterCombinations(string digits) {
        map['2'] = {'a','b','c'};
        map['3'] = {'d','e','f'};
        map['4'] = {'g','h','i'};
        map['5'] = {'j','k','l'};
        map['6'] = {'m','n','o'};
        map['7'] = {'p','q','r','s'};
        map['8'] = {'t','u','v'};
        map['9'] = {'w','x','y','z'};

        helper(digits,0,"");
        return result;        
    }
    void helper(string digits, int i, string str){
        for(int pos = 0; pos < map[digits[i]].size(); pos++){
            str.push_back(map[digits[i]][pos]);
            if(str.size() == digits.size()){
                result.push_back(str);
            }
            helper(digits,i + 1, str);
            str.pop_back();
        }
    }
};