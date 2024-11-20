#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>
#include  <climits>
using namespace std;

int vitamin(int n, vector<pair<int,string>>& v){
    vector<int> dp(8, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i< n; i++){
        int bitmask = 0;
        for(char k : v[i].second){
            if(k == 'A') bitmask |= 1;
            if(k == 'B') bitmask |= 2;
            if(k == 'C') bitmask |= 4;
        }
        
        // cout<<bitmask<<endl;
        for(int j = 0; j <= 7; j++){
            if(dp[j] != INT_MAX){
                dp[bitmask | j] = min(dp[bitmask | j], dp[j] + v[i].first);
            }

            
        }
        
    }
    return dp[7] == INT_MAX ? -1 : dp[7];
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,string>> v;
    
    
    for (int i = 0; i < n; ++i) {
        int num;
        int code;
        string str;
        cin >> num >> str;  // Read each pair of an integer and a string
        
        v.push_back(make_pair(num, str));  // Store the pair in the vector
    }
    cout<<vitamin(n,v)<<endl;
    // cout<< "hello world"<<endl;
    return 0;
}
