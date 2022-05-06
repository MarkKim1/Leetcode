class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> s_hash(26,0);
        vector<int> p_hash(26,0);
        vector<int> result;
        int s_size = s.size();
        int p_size = p.size()-1;
        int start = 0;
        int left = 0;
        int right = 0;
        if(p.size() > s.size()){
            return result;
        }
        for(int i = 0; i < p.size(); i++){
            p_hash[p[i] - 'a']++;
            s_hash[s[i]-'a']++;
            right++;
        }
        
        while(right <= s_size){
            if(s_hash == p_hash){
                result.push_back(left);
            }
            if(right < s_size){
            s_hash[s[left++]-'a']--;
            s_hash[s[right++]-'a']++;
            }
            else{
                break;
            }
        }
        return result;
    }
};