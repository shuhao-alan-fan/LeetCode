class Solution:
    def longestPalindrome(self, s: str) -> str:
        if(len(s) == 0): return ""
        if(len(s) == 1): return s
        max_len = 0
        ans = ""
        for i in range(1,len(s)*2 - 1):
            r = (i+1)//2
            l = i//2
            counter = 0
            while(l >= 0 and r < len(s) and s[l] == s[r]):
                    counter = r-l+1
                    if(counter > max_len):
                        max_len = counter
                        ans = s[l:r+1]
                    l -= 1
                    r += 1
        return ans