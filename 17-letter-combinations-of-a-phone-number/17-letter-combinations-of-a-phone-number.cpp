class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> map = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        vector<string> container;
        for(int i = 0; i < digits.size(); i++){
            container.push_back(map[digits[i]]);
        }
        vector<string> result;
        if(digits.empty()) return result;
        string sub = "";
        helper(0,container,result,sub);
        container.clear();
        map.clear();
        return result;
    }
    void helper(int i,vector<string>& container, vector<string>& result, string& sub){
        if(i >= container.size()){
            result.push_back(sub);
            return;
        }
        for(int n = 0; n < container[i].size(); n++){
            sub+=container[i][n];
            helper(i+1,container,result,sub);
            sub.pop_back();
        }
    }
};