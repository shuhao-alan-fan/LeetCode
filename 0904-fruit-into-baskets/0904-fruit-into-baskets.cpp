class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0,  left = 0;
        int kind = 0;
        unordered_map<int,int> fmap;
        for(int  right = 0; right<fruits.size();  right++){ 
            if(fmap[fruits[right]]++ == 0) kind++;
            while(kind > 2){   
                if(--fmap[fruits[left++]] == 0) --kind;
            }
            
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};