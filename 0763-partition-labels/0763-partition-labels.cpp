class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> map;
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            map[s[i]] = i;
        }
        int end = INT_MIN;
        int size = 0;
        for(int i = 0; i < s.size(); i++){
            size++;
            end = max(end,map[s[i]]);
            if(end == i){
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;
    }
};