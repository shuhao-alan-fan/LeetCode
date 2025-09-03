class Solution {
public:
    double myPow(double x, int n) {
        double ans;
        if(n==0) return 1.0;
        ans = rec(x,abs(static_cast<long>(n)));
            
        if(n > 0) return ans;
        else{
            return 1/ans;
        }
    
        return 0;
    }
    double rec(double x, long n){
        if(n==0) return 1.0;
        double half = rec(x,n/2);
        if(n% 2 == 0) return half* half;
        else{
            return x* half * half;
        }
    }
};