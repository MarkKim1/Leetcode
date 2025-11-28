class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> maxheap;
        for(int i = 0; i < gifts.size(); i++){
            maxheap.push(gifts[i]);
        }
        while(k--){
            int top = maxheap.top();
            maxheap.pop();    
            maxheap.push(sqrt(top));
        }
        long long result;
        while(!maxheap.empty()){
            result += maxheap.top();
            maxheap.pop();
        }
        return result;
    }
};