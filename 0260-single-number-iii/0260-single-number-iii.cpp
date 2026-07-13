class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0, a=0, b=0;
        for(int &k: nums) xr^=k;
        int rightmostsetbit=0;
        while(!((xr>>rightmostsetbit)&1)) rightmostsetbit++;
        for(int &k: nums) {
            if((k>>rightmostsetbit)&1) a^=k;
            else b^=k;
        }
        return {a, b};
    }
};