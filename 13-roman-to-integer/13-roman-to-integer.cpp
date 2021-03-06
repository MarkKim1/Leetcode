class Solution {
public:
    int romanToInt(string s) {
       unordered_map<char,int> chart{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int result = 0;
        int j = 0; int i = 1;
        int first=0,second = 0;
        if(s.size() == 1){
            return chart[s[0]];
        }
        while(j < s.size()){
            if(chart[s[i]] > chart[s[j]]){
                result +=chart[s[i]]-chart[s[j]];
                //cout << result << endl;
                j+=2;
                i+=2;
            }
            else{
                result +=chart[s[j]];
                //cout << result << endl;
                j++;
                i++;
            }
        }
        return result;
    }
};