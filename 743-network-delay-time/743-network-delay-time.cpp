class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(vector<int> time: times){
            int from = time[0];
            int to = time[1];
            int distance = time[2];
            adj[from].push_back({distance,to});
        }
        vector<int> signal_sum(n+1,INT_MAX);
        int answer = INT_MIN;
        BFS(adj,k,signal_sum);
        signal_sum[k] = 0;
        for(int i = 1; i <=n; i++){
            answer = max(answer,signal_sum[i]);
        }
        return answer == INT_MAX ? -1: answer;
    }
    void BFS(vector<vector<pair<int,int>>>& adj, int k,vector<int>& signal_sum){
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,k});//pq.first = distance, pq.second = node;
        while(!pq.empty()){
            int currnode = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            for(auto neighborNode: adj[currnode]){
                int newWeight = neighborNode.first;
                int nextNode = neighborNode.second;
                if(signal_sum[nextNode] > weight + newWeight){
                    signal_sum[nextNode] = weight + newWeight;
                    pq.push({weight + newWeight,nextNode});
                }
            }
        }
    }
};