class MyCalendar {
    set<pair<int, int>> books;
public:
    bool book(int s, int e) {
        auto next = books.lower_bound({s, e}); // first element with key not go before k (i.e., either it is equivalent or goes after).
        if (next != books.end()){
            if(next->first < e){
                return false;
            }
        }
        if (next != books.begin()){
            if(s < (--next)->second){
                return false;
            }
        }
        books.insert({ s, e });
        return true;
    }
};