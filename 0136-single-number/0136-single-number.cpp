class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int count=1, target=nums[0];
        // for(int i=1; i<nums.size(); i++){
        //     if(count==0){
        //         target=nums[i];
        //         count=1;
        //     }
        //     if(target==nums[i]) count--;
        //     else count++;
        // }
        // return target;
        // map<int, int> mp;
        // for(auto k: nums){
        //     mp[k]++;
        // }
        // for(auto k: mp){
        //     if (k.second==1) return k.first;
        // }
        // return 0;
        int xorr=0;
        for(auto k: nums){
            xorr=xorr^k;
        }
        return xorr;
    }
};