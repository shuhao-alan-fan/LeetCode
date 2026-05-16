class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int arr[60];
        int res = 0;
        for(int t:time){
            int r = t % 60;
            int complement = (60-r) % 60;
            res += arr[complement];
            arr[r]++;
        }
        return res;
    }
};