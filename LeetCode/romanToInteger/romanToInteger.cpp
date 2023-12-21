#include <string>
#include <vector>
#include <map>
using namespace std;
class LeetCode {
public:
    int romanToInt(string s) {
        std::map<char, int> romanInt;
        romanInt['I'] = 1;
        romanInt['V'] = 5;
        romanInt['X'] = 10;
        romanInt['L'] = 50;
        romanInt['C'] = 100;
        romanInt['D'] = 500;
        romanInt['M'] = 1000;
        int number = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(romanInt[s[i]]>= romanInt[s[i+1]])
                number += romanInt[s[i]];
            else{
                number += romanInt[s[i+1]];
                number -=romanInt[s[i]];
                i++;
            }
        }
        return number;
    }
};