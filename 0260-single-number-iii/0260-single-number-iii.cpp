class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // using distinguishing bit of the unqiue elements TC:- O(2*n)
        int a=0, b=0;
        long long xr=0;
        for(int &k: nums) xr^=k;
        int rightmostsetbit=(xr&(xr-1))^xr;
        for(int &k: nums) {
            if(rightmostsetbit&k) a^=k;
            else b^=k;
        }
        return {a, b};

        // more formulaas for isolating rightmost set bit
        // xr^(xr&(xr-1))
        // xr&~(xr-1)
        // xr&(-xr) [-x = ~x + 1]
    }
};