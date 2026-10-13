class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 1;
        int left = 0;
        array<int,26> count{};
        int maxFreq = 0;
        for(int right = 0; right<s.size(); right++){
            maxFreq = max(maxFreq, ++count[s[right] - 'A']);
            if(right - left + 1 - maxFreq > k){
                left++;
                count[s[left] - 'A']--;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};