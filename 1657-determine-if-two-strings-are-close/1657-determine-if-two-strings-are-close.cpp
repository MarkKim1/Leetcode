class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return false;
        }
        unordered_map<char,int> w1;
        unordered_map<char,int> w2;
        for(int i = 0; i < word1.size(); i++){
            w1[word1[i]]++;
        }
        for(int i = 0; i < word2.size(); i++){
            w2[word2[i]]++;
        }
        bool found = false;
        for(auto w1char : w1){
            for(auto w2char : w2){
                if(w1.find(w2char.first) == w1.end()) return false;
                if(w1char.second == w2char.second){
                    found = true;
                    w2.erase(w2char.first);
                    break;
                }
            }
            if(found == false){
                return false;
            }
            found = false;
        }
        return true;
    }
};