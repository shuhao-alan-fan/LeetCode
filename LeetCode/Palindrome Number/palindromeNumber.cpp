#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
bool isPalindrome(int x);
int main(){
    int input;
    cin >> input;
    if(isPalindrome(input)){
        cout << "true";
    }
    else{
        cout << "false";
    }
}
/* My Shit Way*/
/*bool isPalindrome(int x){
    if(x<0){
        return false;
    }
    else if(x == 0){
        return true;
    }
    else{
        string num = to_string(x);
        int count = 0;
        int size = num.size();
        for(int i = 0; i< size; i++){
            if(num[i] == num[size-i-1]){
                count++;
            }
        }
        if (count == num.size()){
            return true;
        }
    }
    return false;
}*/
/* GOOD WAY*/
bool isPalindrome(int x){
    if(x<0 || x!=0 && x%10 ==0 ) return false;
        int check=0;
        while(x>check){
            check = check*10 + x%10;
            x/=10;
        }
    return (x==check || x==check/10);
}
    