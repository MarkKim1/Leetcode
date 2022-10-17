class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alphabet(26,0);
        for(int i = 0; i < sentence.size(); i++){
            alphabet[sentence[i]-'a']++;
        }
        for(int i =0 ; i< alphabet.size(); i++){
            if(alphabet[i] == 0){
                return false;
            }
        }
        return true;
    }
};