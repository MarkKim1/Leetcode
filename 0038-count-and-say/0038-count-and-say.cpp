class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        while(--n){
            string temp = "";
            for(int i = 0; i < curr.size(); i++){
                int count = 1;
                while(i+1 < curr.size() and curr[i] == curr[i+1]){
                    count++;
                    i++;
                }
                temp += to_string(count) + curr[i];
            }
            curr = temp;
        }
        return curr;
    }
};