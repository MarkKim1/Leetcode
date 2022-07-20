
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> dp;
        sort(words.begin(),words.end(),[](const string& word,const string& word1){
                return (word.size() < word1.size());
            });;
        int longestWordSequenceLength = 1;
        for(auto &word: words){
            int presentLength = 1;
            for(int i = 0; i < word.size(); i++){
                string pred = word.substr(0,i) + word.substr(i+1,word.size()+1);
                if(dp.find(pred) != dp.end()){
                    int prevLength = dp[pred];
                    presentLength = max(presentLength,prevLength+1);
                }
            }
            dp[word] = presentLength;
            longestWordSequenceLength = max(longestWordSequenceLength,presentLength);
        }
        return longestWordSequenceLength;
    }
    
};