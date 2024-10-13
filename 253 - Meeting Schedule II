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
    int minMeetingRooms(vector<Interval>& intervals) {
        int counter = 0;
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(),intervals.end(),[](const Interval &a, const Interval &b){
            return a.start < b.start;
        });
        for(auto i : intervals){
            cout<<"("<<i.start<<","<<i.end<<")"<<endl;
        }
        vector<int> v;

        v.push_back(intervals[0].end);
        
        counter += 1;
        int lastend = v.back();
        for(int i = 1; i<intervals.size();i++){
            bool b = false;
            for(int j = 0; j<v.size(); j++){
                if(v[j] <= intervals[i].start){
                    b = true;
                    v[j] = intervals[i].end;
                    break;
                }
                
            }
            if(!b){
                v.push_back(intervals[i].end);
                counter++;
            }
            

        }
        return counter;
    }
};
