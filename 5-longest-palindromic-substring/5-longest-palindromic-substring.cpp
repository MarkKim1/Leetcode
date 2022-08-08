class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int n = 1; n < s.size(); n++){
            if(s[n-1] == s[n+1]){
                string temp = s.substr(n-1,3);
                if(ans.size() <= temp.size()){
                    ans = temp;
                }
                int left = n-1,right = n+1;
                while(left > 0 and right < s.size()){
                    left--;
                    right++;
                    if(s[left] == s[right]){
                        string temp = s.substr(left,right-left+1);
                        if(ans.size() <= temp.size()){
                            ans = temp;
                        }    
                    }else{
                        break;
                    }
                }
            }if(s[n-1] == s[n]){
                string temp = s.substr(n-1,2);
                if(ans.size() <= temp.size()){
                    ans = temp;
                }
                int left = n-1,right = n;
                while(left > 0 and right < s.size()){
                    left--;
                    right++;
                    if(s[left] == s[right]){
                        string temp = s.substr(left,right-left+1);
                        if(ans.size() <= temp.size()){
                            ans = temp;
                        }    
                    }else{
                        break;
                    }
                }
            }
        }
        if(ans.empty()){
            ans = s[0];
            return ans;
        }
        return ans;
    }
};