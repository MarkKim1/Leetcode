class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        long long count = 0;
        for(auto a : nums){
            count+=a;
            str.push_back(to_string(a));
        }
        if(count == 0) return "0";
        sort(str.begin(),str.end(),[](string s1, string s2){return s1+s2 > s2+s1;});
        string result = "";
        for(int i = 0; i < str.size(); i++){
            result+=str[i];
        }
        return result;
    }
};