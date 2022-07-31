class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minheap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> maxheap;
        for(auto interval: intervals){
            minheap.push(make_pair(interval[0],interval[1]));
        }
        while(!minheap.empty()){
            auto temp = minheap.top();
            minheap.pop();
            if(maxheap.empty()){
                maxheap.push(make_pair(temp.second,temp.first));
            }
            else if(maxheap.top().first <= temp.first){
                maxheap.pop();
                maxheap.push(make_pair(temp.second,temp.first));
            }else{
                maxheap.push(make_pair(temp.second,temp.first));
            }
        }
        return maxheap.size();
    }
};