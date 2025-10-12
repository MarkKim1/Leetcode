class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string s = "";
        vector<string> vec;
        
        for(int i = 0; i < path.size(); i++){
            if(s != "" and path[i] == '/'){
                if(s == "/.."){
                    if(!vec.empty()) vec.pop_back();
                }else{
                    if(s != "/." and s != "/") vec.push_back(s);
                }
                s.clear();
            }
            s += path[i];
        }
        if(!vec.empty() and s == "/..") vec.pop_back();
        else if(s != "/." and s != "/" and s != "/..") vec.push_back(s);
        
        string ans = "";
        for(int i = 0; i < vec.size(); i++){
            ans += vec[i];
        }
        return ans.empty() ? "/" : ans;
    }
};