class Solution {
public:
    int divide(int dividend, int divisor) {
        // //repeated subtraaction TC:-O(dividend/divisor)
        // if(dividend==INT_MIN && divisor==-1) return INT_MAX; //edge case
        // int sign=1;
        // if(dividend<0 ^ divisor<0) sign=-1;
        // long long dvd=llabs(dividend);  //llabs is used because abs(-2147483648) won't work
        // long long dvs=llabs(divisor);
        // if(dvd == dvs) return sign;
        // if(dvs == 1) return (int)(dvd*sign);   
        // int count=0;
        // while(dvd>=dvs){
        //     dvd-=dvs;
        //     count++;
        // }
        // return count*sign;

        // bit manipulaton
        if(dividend==INT_MIN && divisor==-1) return INT_MAX; 
        int sign=1;
        if(dividend<0 ^ divisor<0) sign=-1;
        long long dvd=llabs(dividend);
        long long dvs=llabs(divisor);
        int count=0;
        if(dvs==1) return (int)(dvd*sign);
        int ans=0;
        while(dvd>=dvs){
            int count=0;
            //multiplying by 2(base) is exactly the same as shifting every bit one place to the left.
            //like in decimal multiplying by 10 shift every digit one digit left by adding zero
            while(dvd>=(dvs<<(count+1))) count++;
            ans+=(1<<count);  //2^count
            dvd=dvd-(dvs<<count);
        }
        return sign*ans;
    }
};