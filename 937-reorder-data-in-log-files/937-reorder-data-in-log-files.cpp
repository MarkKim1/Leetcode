class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
       vector<string> ans;
        vector<pair<string,string>> sub;
        vector<string> digit;
        for(auto &s:logs){
            int i = 0;
            while(s[i] != ' ') i++;
            if(isalpha(s[i+1])){
                sub.push_back(make_pair(s.substr(0,i),s.substr(i+1)));
            }else{
                digit.push_back(s);
            }
        }
        stable_sort(sub.begin(),sub.end(),[&](auto a,auto b){
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        for(auto a:sub){
            ans.push_back(a.first+ ' ' + a.second);
        }
        for(auto a:digit){
            ans.push_back(a);
        }
        return ans;
    }
};