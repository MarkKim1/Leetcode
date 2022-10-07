class MyCalendar {
    vector<pair<int,int>> calender;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto [s,e] : calender){
            if(start < e and s < end){
                return false;
            }
        }
        calender.emplace_back(start,end);
        return true;
    }
       
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */