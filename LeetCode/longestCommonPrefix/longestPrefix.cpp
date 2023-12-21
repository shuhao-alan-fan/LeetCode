 
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <iostream>
 using namespace std;
    string longestCommonPrefix(vector<string>& v);

 int main(){
    //cout<< "hello world";
    vector<string> strs;
    strs.push_back(" 12345");
    strs.push_back(" 123456");
    string ans = longestCommonPrefix(strs);
    cout<< ans;
    return 0;
 }
 
 
 string longestCommonPrefix(vector<string>& strs) {
       
     string ans = "";
     /**************************************/
        sort(strs.begin(), strs.end());
     /**************************************/
        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];
        for(int i = 0; i< min(first.size(), last.size()); i++){
            if(first[i] != last[i]){
                return ans;
            }
            ans += first[i];
        }
        return ans;     
}