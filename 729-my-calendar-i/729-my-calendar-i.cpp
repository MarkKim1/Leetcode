class MyCalendar {
    set<pair<int,int>> set;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int,int> pair = make_pair(start,end);
        auto next = set.lower_bound(pair);
        if(next != set.end() and next->first < end){
            return false;
        }
        // need to check if next is first index of set so that prev method can be used
        if(next != set.begin()){ 
            auto a = prev(next);
            if(a->second > start){
                return false;
            }
        }
        set.insert(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */