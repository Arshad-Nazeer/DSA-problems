class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a=0, b=0;
        long long xr=0;
        for(int &k: nums) xr^=k;
        int rightmostsetbit=(xr&(xr-1))^xr;
        for(int &k: nums) {
            if(rightmostsetbit&k) a^=k;
            else b^=k;
        }
        return {a, b};
    }
};