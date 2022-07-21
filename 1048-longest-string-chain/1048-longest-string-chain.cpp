class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string& word1, const string& word2){
            return word1.size() < word2.size();
        });
        unordered_map<string,int> dp;
        int longest = 1;
        for(int i = 0; i < words.size(); i++){
            int currLongestCount = 1;
            string currString = words[i];
            for(int j = 0; j < currString.size(); j++){
                string stringToCompare = currString.substr(0,j) + currString.substr(j+1,currString.size()+1);
                if(dp.find(stringToCompare) != dp.end()){
                    int dpVal = dp[stringToCompare];
                    currLongestCount = max(currLongestCount,dpVal+1);
                }
                dp[currString] = currLongestCount;
                longest = max(longest,currLongestCount);
            }
        }
        return longest;
    }
};