class Solution {
public:
    int divide(int dividend, int divisor) {
        //repeated subtraaction
        if(dividend==INT_MIN && divisor==-1) return INT_MAX; //edge case
        int sign=1;
        if(dividend<0 ^ divisor<0) sign=-1;
        long long dvd=dividend;  //llabs is used because abs(-2147483648) won't work
        long long dvs=divisor;
        dvd=llabs(dvd);
        dvs=llabs(dvs);
        if(dvd == dvs) return sign;
        if(dvs == 1) return (int)(dvd*sign);   
        int count=0;
        while(dvd>=dvs){
            dvd-=dvs;
            count++;
        }
        return count*sign;
    }
};