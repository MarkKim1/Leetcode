class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wset(wordList.begin(),wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ans = 1;
        
        while(not todo.empty()){
            int size = todo.size();
            
            for(int i = 0; i < size; i++){
                string word = todo.front();
                if(word == endWord){
                    return ans;
                }
                todo.pop();
                wset.erase(word);
                for(int i = 0; i< word.size(); i++){
                    char c = word[i];
                    for(int j = 0; j <=26; j++){
                        word[i] = 'a' + j;
                        if(wset.find(word) != wset.end()){
                            todo.push(word);
                        }
                    }
                    word[i] = c;
                }
            }
            ans++;
        }
        return 0;
    }
};