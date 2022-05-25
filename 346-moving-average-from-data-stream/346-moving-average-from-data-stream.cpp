class MovingAverage {
public:
    int capacity;
    double sum = 0;
    vector<int> ans;
    MovingAverage(int size) {
        capacity = size;
    }
    double next(int val) {
        
        if(ans.size() < capacity){
            ans.push_back(val);
            sum+=val;
            return sum / ans.size();
        }
        if(ans.size() == capacity){
            sum = 0;
            for(int i = 0; i < ans.size(); i++){
                if(i == ans.size()-1){
                    ans[i] = val;
                    sum+=ans[i];
                    break;
                }
                ans[i] = ans[i+1];
                sum +=ans[i];
            }   
        }
        return sum / ans.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */