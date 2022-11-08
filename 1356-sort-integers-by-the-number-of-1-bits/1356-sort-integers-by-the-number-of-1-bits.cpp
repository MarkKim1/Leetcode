class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minheap;
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++){
            int count = 0;
            int curr = arr[i];
            while(curr){
                curr = curr & (curr-1);
                count++;
            }
            minheap.push({count,arr[i]});
        }
        while(!minheap.empty()){
            auto curr = minheap.top();
            minheap.pop();
            ans.push_back(curr.second);
        }
        return ans;
    }
};