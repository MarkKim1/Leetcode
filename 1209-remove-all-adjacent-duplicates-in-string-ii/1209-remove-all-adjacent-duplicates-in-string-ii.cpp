class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(!stk.empty() and stk.top().first == s[i]){
                if(stk.top().second == k-1){
                    for(int j = 0; j < k-1; j++){
                        stk.pop();
                    }
                }else{
                    stk.push(make_pair(s[i],stk.top().second + 1));
                }
            }else{
                stk.push(make_pair(s[i],1));
            }
        }
        while(!stk.empty()){
            ans.push_back(stk.top().first);
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};