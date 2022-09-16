class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int,string>> candidate;
        vector<string> result;
        unordered_map<string,int> map;
        priority_queue<pair<int,string>> maxheap;
        for(int i = 0; i < words.size(); i++){
            map[words[i]]++;
        }
        for(auto a : map){
            maxheap.push(make_pair(-a.second,a.first));
            if(maxheap.size() > k) maxheap.pop();
        }
        while(!maxheap.empty()){
            candidate.push_back(maxheap.top());
            maxheap.pop();
        }
        sort(candidate.begin(),candidate.end());
        for(auto a : candidate){
            result.push_back(a.second);
        }
        return result;
    }
};