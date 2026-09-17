class Solution {
public:
    int bestClosingTime(string customers) {
        // vector<int> count(customers.size()+1);
        // for(int i = 0; i<count.size(); i++){
        //     int cnt = 0;
        //     for(int j = 0; j<customers.size(); j++){ //closes at ith hour & customer came at jth hour
        //         if((j <  i && customers[j] == 'N') || (j >= i && customers[j] == 'Y')){
        //             cnt++;
        //         }
        //     }
        //     count[i] = cnt;
        // }
        vector<int> dp(customers.size() + 1);
        int nos = 0;
        for(char c: customers){
            if(c == 'N'){
                nos++;
            }
        }
        dp[customers.size()] = nos;
        for(int i = customers.size() - 1; i>=0; i--){
            if(customers[i] == 'Y') dp[i] = dp[i+1] + 1;
            else dp[i] = dp[i+1] - 1;
        }
        vector<pair<int,int>> ans;
        for(int i = 0; i<customers.size()+ 1; i++){
            
            ans.push_back({dp[i],i});
        }
        sort(ans.begin(),ans.end());
        return ans[0].second;
    }
};