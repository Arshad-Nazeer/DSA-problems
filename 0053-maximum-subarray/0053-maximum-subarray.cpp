class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int ressum=INT_MIN;
        // for(int i=0; i<nums.size(); i++){
        //     int sum=0;
        //     for(int j=i; j<nums.size(); j++){
        //         sum+=nums[j];
        //         ressum=max(sum, ressum);
        //     }
        // }  
        // return ressum;
        

        // vector<int> v(nums.size());
        // int maxsum=nums[0];
        // v[0]=nums[0];
        // for(int i=1; i<nums.size(); i++){
        //     v[i]=max(nums[i], nums[i]+v[i-1]);
        //     maxsum=max(v[i], maxsum);
        // }
        // return maxsum;

        int currsum=nums[0], maxsum=nums[0];
        for(int i=1; i<nums.size(); i++){
            currsum=max(nums[i], nums[i]+currsum);
            maxsum=max(maxsum, currsum);
        }
        return maxsum;
    }
};