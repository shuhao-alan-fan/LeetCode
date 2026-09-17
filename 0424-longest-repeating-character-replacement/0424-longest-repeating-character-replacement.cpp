class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxFreq = 0, best = 0;
        array<int,26> count{};
        for(int right = 0; right<s.size(); right++){
            maxFreq = max(maxFreq, ++count[s[right] - 'A']);

            if(right - left + 1 - maxFreq > k){
                count[s[left] - 'A']--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};