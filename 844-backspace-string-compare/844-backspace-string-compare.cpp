class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> s1;
        vector<char> s2;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '#'){
                s1.push_back(s[i]);
            }
            else{
                if(!(s1.empty()))
                   s1.pop_back();
            }
        }
        for(int i = 0; i < s1.size(); i++){
            cout << s1[i];
        }
        cout << endl;
        for(int i = 0; i < t.size(); i++){
            if(t[i] != '#'){
                s2.push_back(t[i]);
            }
            else{
                if(!(s2.empty()))
                   s2.pop_back();
            }
        }
        for(int i = 0; i < s2.size(); i++){
            cout << s2[i];
        }
        if(s1 == s2){
            return true;
        }
        return false;
    }
};