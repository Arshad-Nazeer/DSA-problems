class Solution {
public:
    // bool check(int n){
    //     if(n==1) return true;
    //     if(n%2!=0) return false;
    //     return check(n/2);
    // }

    bool isPowerOfTwo(int n) {
        //brian kernighan O(1)
        if(n<=0) return false;
        int count=0;
        while(n) {
            n=n&(n-1);  //it removes rightmose set bit
            count++;
            if(count>1) return false;
        }
        return count==1;

        // //this function counts number of set bits
        // if(n<=0) return 0;
        // return __builtin_popcount(n)==1;

        // // set bits is only one TC:- O(1)
        // if(n<=0) return false;
        // int count=0;
        // for(int i=0; i<32; i++){
        //     if(n & (1 << i)) count++;
        //     if(count>1) return false;
        // }
        // return count==1;

        // //left shifting bit
        // if(n<=0) return false;
        // for(int i=0; i<32; i++){
        //     if(n==(1<<i)) return true;
        // }
        // return false;

        // // repeated division TC:-O(log n)
        // if(n<=0) return false;
        // while(n%2==0) n=n/2;
        // return n==1;

        // //recursion
        // if(n<=0) return false;
        // return check(n);

        // //log2 approach
        // if(n<=0) return false;
        // double two=log2(n);
        // return floor(two)==two;
    }
};