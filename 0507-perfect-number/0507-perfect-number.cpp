class Solution {
public:
    bool checkPerfectNumber(int num) {
        // // brute TC:-O(n)
        // int ans=0;
        // for(int i=1; i<num; i++){
        //     if(num%i==0) ans+=i;
        // }
        // return ans==num;

        // optimal TC:-O(sqrt(n))
        int ans=0;
        for(int i=1; i*i<=num; i++){
            if(num%i==0) {
                ans+=i;
                if(i!=num/i) ans+=num/i;
            } 
        }
        ans-=num;
        return ans==num;
    }
};