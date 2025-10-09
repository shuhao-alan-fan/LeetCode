class Solution {
public:
    // O(n * m) bad
    // O(nlogm)
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(auto i:spells){
            ans.push_back(valid_potions(potions,i,success));
        }
        return ans;
    }

    //nlogn
    int valid_potions(vector<int>& potions, int spell, long long success){
        int l = 0;
        int r = potions.size() - 1;
        long long target = (success + (long long)spell - 1) / (long long)spell;
        int res = potions.size();
        //binary search to find the least value that is greater than or equal to target.
        while(l<=r){
            int m = l + (r - l) / 2;
            if((long long)potions[m] >= target){
                res = m;
                r = m - 1;
            }
            else{
                l = m+1;
            }
        }
        return potions.size() - res;
    }
};