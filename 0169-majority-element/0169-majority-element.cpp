class Solution {
public:
    int majorityElement(vector<int>& nums) {        
        // unordered_map<int, int> mp;
        // for(int i=0; i<nums.size(); i++){
        //     mp[nums[i]]++;
        //     if(mp[nums[i]]>nums.size()/2) return nums[i];
        // }
        // return 0;
        int target=nums[0], count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target) count++;
            else count--;
            if(count==0) {
                target=nums[i];
                count=1;
            }
        }
        return target;
    }
};