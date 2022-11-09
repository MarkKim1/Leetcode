class Solution {
public:
    string countAndSay(int n) {
        string count_to_say = "1";
        while(--n){
            string temp = "";
            for(int i = 0; i < count_to_say.size(); i++){
                int count = 1;
                while(i + 1 < count_to_say.size() and count_to_say[i] == count_to_say[i+1]){
                    count++;
                    i++;
                }
                temp += to_string(count) + count_to_say[i];
            }
            count_to_say = temp;
        }
        return count_to_say;
    }
};