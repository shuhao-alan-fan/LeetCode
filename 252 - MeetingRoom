/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()) return true;
        sort(intervals.begin(),intervals.end(), [](const Interval & a, const Interval & b){
            return a.start < b.start;
        });
        vector<Interval> v;
        v.push_back(intervals[0]);
        int last_end = v.back().end;
        for(int i = 1; i<intervals.size();i++){
            
            if(last_end  >  intervals[i].start){
                return false;
            }
            last_end = intervals[i].end;
        }

        return true;
    }
};
