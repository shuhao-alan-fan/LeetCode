class Twitter {
public:
    unordered_map<int,vector<int>> follows;
    vector<pair<int,int>> tweets;

    Twitter() {
        
    }
    
    bool is_following(int id, int following_id){
        if(id == following_id) return true;
        for(int i : follows[id]){
            if(i == following_id){
                return true;
            }
        }
        return false;
    }

    void postTweet(int userId, int tweetId) {
        tweets.push_back(make_pair(userId,tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int k = 0;
        reverse(tweets.begin(),tweets.end());
        for(pair<int,int> i : tweets){
            if(k == 10) break;
            if(is_following(userId, i.first)){
                feed.push_back(i.second);
                k++;
            }
        }
        reverse(tweets.begin(),tweets.end());
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        for(int i=0; i<follows[followerId].size(); i++){
            if(follows[followerId][i] == followeeId){
                follows[followerId].erase(follows[followerId].begin()+i);
            }
        }
    }
};