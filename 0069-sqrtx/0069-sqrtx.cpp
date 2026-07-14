class Solution {
public:
    int mySqrt(int x) {
        // // HEHE Library go brrrrr
        // return int(sqrt(x));

        // // LAAND APPROACH
        // for(long long i=0; i<=x; i++){
        //     if(i*i==x) return i;
        //     else if(i*i>x) return (int)i-1;
        // }
        // return 0;

        // // Binary Search
        long long high=x, low=0;
        int ans;

        while(high>=low){
            long long mid=(high+low)/2;
            if(mid*mid<=x){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};