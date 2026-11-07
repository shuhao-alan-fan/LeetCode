class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int ans = 0;
        vector<int> v(128,0);
        for(int right = left; right<s.size(); right++){
            v[s[right]]++;
            
            while(v[s[right]] > 1){
                v[s[left++]]--;
            }
            
            ans = max(ans, right - left + 1);

        }
        return ans;
    }
};