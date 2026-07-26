class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxval=INT_MIN, minval=INT_MAX;
        for(int &x: nums){
            maxval=max(maxval, x);
            minval=min(minval, x);
        }

        
        // // decrement from minval TC:- O(n+minval);
        // // for(int i=minval; i>=1; i--){
        // //     if(minval%i==0 && maxval%i==0) return i;
        // // }
        // // return 1;

        // //euclidean subtraction TC:-O(n+max(a,b))
        // while(minval!=0 && maxval!=0){
        //     maxval > minval ? maxval=maxval-minval : minval=minval-maxval;
        // }
        // return minval==0? maxval: minval;

        // euclidean divison TC:-(n+log(min(a, b)))
        while(minval!=0){
            int rem=maxval%minval;
            maxval=minval;
            minval=rem;            
        }
        return maxval;

        // //inbuilt function
        // return gcd(minval, maxval);
    }
};