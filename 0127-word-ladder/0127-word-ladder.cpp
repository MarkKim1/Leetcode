class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> set(wordList.begin(),wordList.end());
        q.push({beginWord,1});

        while(!q.empty()){
            auto [first,second] = q.front();
            q.pop();
            if(first == endWord) return second;
            for(int i = 0; i < first.size(); i++){
                string original = first;
                for(int j = 0; j < 26; j++){
                    first[i] = 'a' + j;
                    if(set.find(first) != set.end()){
                        set.erase(first);
                        q.push({first,second + 1});
                    }
                }
                first = original;
            }
        }
        return 0;
    }
};