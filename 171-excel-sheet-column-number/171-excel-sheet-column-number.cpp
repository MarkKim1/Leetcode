class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int result = 0;
        for(int i = 0; i < n; i++){
            result *= 26;
            result+=(columnTitle[i]-'A' +1);
        }
        return result;
    }
};