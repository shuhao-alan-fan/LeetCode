class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> m;
        int res = 0;
        for(string word: words){
            m[word]++;
        }
        bool hasCenter = false;
        for(auto& [w,count]: m){
            
            if(w[0] == w[1]){
                if(count %2 == 0){
                    res += count*2;
                }
                else if(count %2 != 0 && !hasCenter){
                    res += 2;
                    hasCenter = true;
                    res += (count-1)*2;
                }
                else if (count%2 != 0 && hasCenter){
                    res+= (count-1)*2;
                }
            }
            
            else if (w[0] != w[1]){
                string cp = {w[1],w[0]};
                int cnt = min(count, m[cp]);
                m[w] -= cnt;
                m[cp] -= cnt;
                res+= 4* cnt;
            }
            
            
        }
        return res;
    }
};