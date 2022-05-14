class Solution {
public:
    vector<int> getPi(string p){
        vector<int>pi(p.size(),0);
        int j = 0;
            for(int i  = 1; i < p.size(); i++){
            while(j > 0 && p[i] != p[j]){
                j = pi[j-1];
            }
            if(p[i] == p[j]){
                pi[i] = ++j;
            }
        }
        return pi;
    }
    
    int strStr(string haystack, string needle) {
        int n = needle.size();
        auto pi = getPi(needle);
        int j = 0;
        for(int i = 0; i < haystack.size(); i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = pi[j-1];
            }
            if(haystack[i] == needle[j]){
                if(j == needle.size()-1){
                    return i-needle.size()+1;
                }else{
                    j++;
                }
            }
        }
        return -1;
    }
};