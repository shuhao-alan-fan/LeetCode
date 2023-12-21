 
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <iostream>
 using namespace std;
 bool isValid(string s);

 int main(){
    string s = "(){}[]";
    isValid(s);
    return 0;
 }
 
 
 bool isValid(string s) {
    if(s[0] == '('){
        for(int i = 1; i < s.size();i++){
            if(s[i] = ')'){
                
            }
        }
    }
}