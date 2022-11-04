class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> map;
        int rest = 0;
        int ans = 0;
        for(auto word: words){
            if(word[0] == word[1]){
                if(map[word] > 0){
                    ans+=4;
                    map[word]--;
                    rest--;
                }else{
                    map[word]++;
                    rest++;
                }
            }else{
                string temp = word;
                reverse(temp.begin(),temp.end());
                if(map[temp]>0){
                    ans+=4;
                    map[temp]--;
                }else{
                    map[word]++;
                }
            }
        }
        if(rest > 0) ans +=2;
        return ans;
    }
};