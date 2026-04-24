class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int origin = 0;
        int count = 0;
        for(char move : moves){
            if(move == 'L') origin--;
            else if(move == 'R') origin++;
            else{
                count++;
            }
        }
        return max(abs(origin + count),abs(origin-count));
    }
};