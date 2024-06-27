class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums)%2:
            return False
        dp = set()
        dp.add(0)
        target = sum(nums) // 2 
        for i in range(len(nums)):
            nextDP = dp.copy()
            for t in dp:
                nextDP.add(t)
                nextDP.add(t+nums[i])
                nextDP.add(nums[i])
            dp = nextDP
        for i in dp:
            print(i)
        return True if target in dp else False
