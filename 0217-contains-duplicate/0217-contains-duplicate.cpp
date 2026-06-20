class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i:nums){
            if(m.find(i) != m.end()) return true;
            else{
                m[i]++;
            }
        }
        return false;
    }
};