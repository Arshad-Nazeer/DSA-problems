class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(n<0) {
            x=1/x;
            N=-N;
        }
        //Non recursion:-
        // long double ans=1;
        // while(N!=0){
        //     if(N%2!=0) {
        //         ans*=x;
        //     }
        //     x*=x;
        //     N=N/2;
        // }
        // return ans;

        //recursion
        // if(N==0) return 1;
        // else if(N%2!=0) return x*myPow(x, N-1);
        // else {
        //     double half=myPow(x, N/2);
        //     return half*half;
        // }

        // bit manipulation
        long double ans=1;
        while(N!=0){
            if(N&1) ans*=x;
            x*=x;
            N=N>>1;
        }
        return ans;
    }
};