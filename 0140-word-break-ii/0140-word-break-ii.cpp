class Trie {
    public:
    string word = "";
    vector<Trie*> children;
    Trie(){
        for(int i = 0; i < 26; i++){
            children.push_back(NULL);
        }
    }
};
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie* trie = new Trie();
        vector<string> ans;
        for(auto word : wordDict){
            Trie* temp = trie;
            for(char ch : word){
                if(temp->children[ch-'a'] == NULL){
                    temp->children[ch-'a'] = new Trie();
                }
                temp = temp->children[ch-'a'];
            }
            temp->word = word;
        }
        DFS("",0,s,trie,ans);
        return ans;
    }
    void DFS(string curr, int index, string s, Trie* trie,vector<string>& ans){
        if(index == s.size()){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        Trie* temp = trie;
        for(int i = index; i < s.size(); i++){
            if(temp->children[s[i]-'a'] != NULL){
                temp = temp->children[s[i]-'a'];
                if(temp->word.size() > 0){
                    curr = curr + temp->word + " ";
                    DFS(curr,i+1,s,trie,ans);
                    for(int i = 0; i <= temp->word.size(); i++){
                        curr.pop_back();
                    }
                }
            }else{
                return;
            }
        }
    }
};