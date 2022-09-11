class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char,int> map;
        queue<pair<int,int>> q;
        for(int i = 0; i < tasks.size(); i++){
            map[tasks[i]]++;
        }
        for(auto a : map){
            pq.push(a.second);
        }
        int time = 0;
        while(!pq.empty() or !q.empty()){
            time++;
            if(!pq.empty()){
                int front = pq.top()-1;
                if(front){
                    q.push(make_pair(front,time+n));
                }
                pq.pop();
            }
            if(!q.empty() and time == q.front().second){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};