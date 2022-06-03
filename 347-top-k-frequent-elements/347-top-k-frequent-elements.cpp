class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>>pq;
        sort(nums.begin(),nums.end());
        int freq = 0;
        int comp = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == comp){
                freq++;
            }else{
                pq.push(make_pair(freq,comp));
                comp = nums[i];
                freq = 0;
            }
        }
        pq.push(make_pair(freq,comp));
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};