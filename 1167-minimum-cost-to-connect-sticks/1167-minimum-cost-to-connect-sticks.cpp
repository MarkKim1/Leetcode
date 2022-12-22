class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int ans = 0;
        priority_queue<int,vector<int>,greater<>> pq;
        for(int i = 0; i < sticks.size(); i++){
            pq.push(sticks[i]);
        }
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int sum = a + b;
            ans += sum;
            pq.push(sum);
        }
        return ans;
    }
};