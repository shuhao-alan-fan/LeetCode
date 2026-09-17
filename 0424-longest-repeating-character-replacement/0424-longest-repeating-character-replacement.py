class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left = max_freq = 0
        count = Counter()
        best = 0
        for right, ch in enumerate(s):
            count[ch] += 1
            max_freq = max(max_freq, count[ch])
            if(right - left + 1 - max_freq > k):
                count[s[left]] -= 1
                left += 1
            best = max(right - left + 1, best)
        return best
