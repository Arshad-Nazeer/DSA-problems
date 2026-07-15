class Solution {
public:
    bool checkPerfectNumber(int num) {
        // // brute TC:-O(n)
        // int ans=0;
        // for(int i=1; i<num; i++){
        //     if(num%i==0) ans+=i;
        // }
        // return ans==num;

        // optimal
        if(num==1) return false;
        int ans=0, i;
        for(i=1; i*i<num; i++){
            if(num%i==0) ans+=i+num/i;
        }
        ans-=num;
        if(i*i==num) ans+=2*i;
        return ans==num;
    }
};