class Solution {
public:
    bool isPowerOfTwo(int n) {
        // set bit counter
        if(n<=0) return false;
        int count=0;
        for(int i=0; i<31; i++){
            if(n & (1 << i)) count++;
            if(count>1) return false;
        }
        return count==1;
    }
};