class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string input;
        vector<string> vec;
        while(getline(ss,input,' ')){
            if(input == ""){
                continue;
            }
            vec.push_back(input);
        }
        string ans = "";
        for(int i = vec.size()-1; i >= 0; i--){
            ans+=vec[i];
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};