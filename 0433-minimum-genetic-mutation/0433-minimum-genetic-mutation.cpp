class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<int> st;
        int count = 0;
        queue<string>q;
        q.push(start);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string curr = q.front();
                q.pop();
                if(curr == end){
                    return count;
                }
                for(int i = 0; i < bank.size(); i++){
                    int diff = 0;
                    for(int j = 0; j < bank[0].size(); j++){
                        if(curr[j] != bank[i][j]){
                            diff++;
                        }
                    }
                    if(diff == 1 and !st.count(i)){
                        st.insert(i);
                        q.push(bank[i]);
                    }
                }
            }
            count++;
        }
        return -1;
    }
};