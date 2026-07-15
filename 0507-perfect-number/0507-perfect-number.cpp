class Solution {
public:
    bool checkPerfectNumber(int num) {
        // brute TC:-O(n)
        int ans=0;
        for(int i=1; i<num; i++){
            if(num%i==0) ans+=i;
        }
        return ans==num;
    }
};