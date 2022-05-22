class Solution {
public:
    string convertToTitle(int columnNumber) {
        char a;
        string result = "";
        while(columnNumber){
           columnNumber--;
            a='A' + (columnNumber%26);
            result = a + result;
            columnNumber/=26;
        }
        return result;
    }
};