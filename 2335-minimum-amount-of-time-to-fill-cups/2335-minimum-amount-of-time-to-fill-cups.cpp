class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> maxheap;
        for(int i = 0; i < amount.size(); i++){
            maxheap.push(amount[i]);
        }
        int result = 0;
        while(!maxheap.empty()){
            int curr = maxheap.top();
            maxheap.pop();
            if(maxheap.top() == 0){
                result += curr;
                return result;
            }
            if(maxheap.top() > 0){
               curr--;
               int next = maxheap.top();
               maxheap.pop();
               next--; 
               maxheap.push(curr);
               maxheap.push(next);
               result++;
            }
        }
        return result;
    }
};