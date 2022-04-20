class Logger {
    unordered_map<string,int> map;
public:
    Logger() {
        map = {};
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        
        auto iterator = map.find(message);
        if(iterator == map.end()){
            map[message] = timestamp+10;
            return true;
        }
        else{
            if(iterator->second <= timestamp){
                iterator->second = timestamp+10;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */