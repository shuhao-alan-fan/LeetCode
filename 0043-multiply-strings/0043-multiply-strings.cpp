class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        vector<int> res(num1.size() + num2.size(), 0);
        int carry = 0;
        for(int i = 0; i< num1.size(); i++){
            for(int j = 0; j<num2.size(); j++){
                res[i+j] += ((num1[i] - '0') * (num2[j] - '0'));
                // cout<<res[i+j]<<endl;
                res[i+j+1] += res[i+j] / 10;
                res[i+j] %= 10;
            }
            
        }
        int begin = res.size() - 1;
        while(res[begin] == 0 && begin >= 0){
            begin --;
        }
        string ans = "";
        while(begin >= 0){
            ans += to_string(res[begin]);
            begin --;
        }
        return ans;

    }
};