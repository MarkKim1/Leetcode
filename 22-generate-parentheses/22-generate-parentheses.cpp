class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string current;
        current.resize(2*n);
        vector<string> combination;
        generate(current,0,combination);
        return combination;
    }
    void generate(string current, int pos, vector<string>& combination){
        if(pos == current.size()){
            if(valid(current)){
                combination.emplace_back(current);
            }
        }else{
            current[pos] = '(';
            generate(current,pos+1,combination);
            current[pos] = ')';
            generate(current,pos+1,combination);
        }
    }
    bool valid(string current){
        int balance = 0;
        for(auto a:current){
            if(a == '('){
                balance++;
            }else{
                balance--;
            }
            if(balance < 0) return false;
        }
        return (balance == 0);
    }
};