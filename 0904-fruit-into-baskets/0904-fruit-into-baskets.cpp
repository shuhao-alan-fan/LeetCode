class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, best = 0;
        int count = 0;
        unordered_map<int,int> basket;

        for(int right = 0; right < fruits.size(); right++){
            if(basket.count(fruits[right])){
                if(fruits[right] == fruits[right-1]){
                    basket[fruits[right]]++;
                }
                else{
                    basket[fruits[right]] = 1;
                    left = right - 1;
                }
                
                count++;
                best = max(best, count);
                continue;
            }
            //continue...
            //2 fruits picked and new fruit 
            if(basket.size() >= 2){
                basket.erase(fruits[left]);
                basket[fruits[right]]++;

                count = basket[fruits[right - 1]] + basket[fruits[right]];
                left = right - 1;
                
            }
            else{
                basket[fruits[right]]++;
                count++;
            }
            best = max(best, count);
        }
        return best;

    }
};