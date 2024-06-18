class Solution:
    def maxProduct(self, nums: List[int]):
        #the difference is to do kaDane from left to right and right to left
        max_end_here = 1
        max_so_far = -math.inf
        for i in nums:
            max_end_here *= i
            if max_so_far < max_end_here:
                max_so_far = max_end_here
            if max_end_here == 0:
                max_end_here = 1
        max_end_here = 1
        for i in reversed(nums):
            max_end_here *= i
            if max_so_far < max_end_here:
                max_so_far = max_end_here
            if max_end_here == 0:
                max_end_here = 1
        return max_so_far