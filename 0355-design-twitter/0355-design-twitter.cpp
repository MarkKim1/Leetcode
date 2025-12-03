class Twitter {
    using int2 = pair<int,int>;
public:
    unordered_map<int,set<int>> following;
    unordered_map<int,vector<int2>> tweets;    
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<int2> maxheap;
        for(auto tweet: tweets[userId]){
            maxheap.push(tweet);
        }
        for(auto person: following[userId]){
            for(auto tweet: tweets[person]){
                maxheap.push(tweet);
            }
        }
        vector<int> feed;
        int count = 10;
        while(!maxheap.empty() and count--){
            auto curr = maxheap.top();
            maxheap.pop();
            feed.push_back(curr.second);
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].erase(followeeId);
        }        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */