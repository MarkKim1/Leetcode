class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto a : nums){
            str.push_back(to_string(a));
        }
        sort(str.begin(),str.end(),[](string s1, string s2){return s1+s2 > s2+s1;});
        string result = "";
        for(int i = 0; i < str.size(); i++){
            if(result[0] == '0'){
                continue;
            }
            result+=str[i];
        }
        return result;
    }
};