class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> map = {
            {"I",1},{"V",5},{"X",10},{"L",50},
            {"C",100},{"D",500},{"M",1000},{"IV",4},
            {"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}
        };
        int result = 0;
        int curr = INT_MIN;
        string currStr = "";
        for(int i = 0; i < s.size(); i++){
            currStr+=s[i];
            if(map.find(currStr) != map.end()){
                curr = max(curr,map[currStr]);
            }else{
                result+=curr;
                string a = "";
                a.push_back(s[i]);
                curr = map[a];
                currStr = s[i];
            }
        }
        result+=curr;
        return result;
    }
};