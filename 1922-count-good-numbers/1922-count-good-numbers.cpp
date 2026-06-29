class Solution {
public:
    const long long MOD=1000000007;

    long long myPow(long long x, long long n){
        if(n==0) return 1;

        long long half=myPow(x, n/2);
        half=(half*half)%MOD;

        if(n%2!=0) half=(half*x)%MOD;
        return half;
    }

    int countGoodNumbers(long long n) {
        // number of even indices=(n+1)/2
        // number of odd indices=n/2
        long long even=(n+1)/2, odd=n/2;
        return (myPow(5, even)*myPow(4, odd))%MOD;

        // return (int)(pow(5, even)*pow(4,odd))%1000000007; // This will cause overflow
    }
};