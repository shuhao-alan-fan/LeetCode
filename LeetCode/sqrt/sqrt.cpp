//必须使用二分法查找（题目要求）
#include <iostream>
using namespace std;
int mySqrt(int x) {
       if (x == 0)
            return x;
        int first = 1, last = x;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            //int mid = (last+first)/ 2;
            // mid * mid == x gives runtime error
            if ((long long)mid*mid == x)
                return mid;
            else if (mid > x / mid) {
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }
        return last;
    }


int main(){
    int num;
    cin>>num;
    cout << mySqrt(num);
}