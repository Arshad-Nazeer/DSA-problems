class Solution {
public:
    int hammingWeight(int n) {
        // int count=0;  TC:-O(32)
        // for(int i=0; i<32; i++){
        //     if(n & (1<<i)) count++;
        // }
        // return count;

        // //shifitng n instead of 1 TC:-O(32)
        // int count=0;
        // while(n){
        //     count+=n&1;
        //     n=n>>1;
        // }
        // return count;

        // // brian-kernighan: it removes the rightmost set bit  O(k) k: number of set bits
        // int count=0;
        // while(n){
        //     n=n&(n-1);
        //     count++;
        // }
        // return count;

        //built in function
        return __builtin_popcount(n);
    }
};