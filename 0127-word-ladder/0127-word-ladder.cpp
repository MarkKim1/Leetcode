class Solution {
public:
    int ladderLength(string a, string b, vector<string>& c) {
        queue<pair<string, int>> q;
        unordered_set<string> set(c.begin(),c.end());
        q.push({a, 1});
        while (!q.empty()) {
            auto [first, second] = q.front();
            q.pop();
            if (first == b)
                return second;
            for (int i = 0; i < first.size(); i++){
                char original = first[i];
                for(char a = 'a'; a <= 'z'; a++){
                    first[i] = a;
                    if(set.count(first)){
                        set.erase(first);
                        q.push({first, second + 1});
                    }
                }
                first[i] = original;
            }
        }
        return 0;
    }
};