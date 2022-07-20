
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> dp;
        sort(words.begin(),words.end(),[](const string& word,const string& word1){
                return (word.size() < word1.size());
            });;
        int longest = 1;
        for(auto word: words){
            int presentlength = 1;
            for(int i = 0; i < word.size(); i++){
                string first = word.substr(0,i);
                string second = word.substr(i+1,word.size()+1);
                string pred = first + second;
                if(dp.find(pred) != dp.end()){
                    int length = dp[pred];
                    presentlength = max(presentlength,length+1);
                }
                dp[word] = presentlength;
                longest = max(longest,presentlength);
            }
        }
        return longest;
    }
    
};