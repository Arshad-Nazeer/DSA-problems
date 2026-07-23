class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n=nums.size();
        // n=(n*(n+1))/2;
        // for(int &x: nums) n-=x;
        // return n;

        //bit manipulation
        int xr=0;
        for(int i=0; i<nums.size(); i++){
            xr^=i+1;
            xr^=nums[i];
        }
        return xr;
    }
};