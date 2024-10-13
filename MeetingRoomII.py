"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        startlist = sorted([i.start for i in intervals])
        endlist = sorted([i.end for i in intervals])

        res, count = 0,0
        s,e = 0,0

        while s < len(startlist):
            if(startlist[s]< endlist[e]): 
                count+=1
                s+=1
                res = max(res, count)
            else:
                count -=1
                e+=1
        return res
