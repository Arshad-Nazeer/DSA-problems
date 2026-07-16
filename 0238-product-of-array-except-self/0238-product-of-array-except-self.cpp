class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //optimized approach
        vector<int> ans(nums.size());
        // int prefix=1;
        int suffix=nums[nums.size()-1];
        ans[0]=1;
        for(int i=1; i<nums.size(); i++){
            ans[i]=ans[i-1]*nums[i-1];
            // ans[i]=prefix;
            // prefix*=nums[i];
        }
        for(int i=nums.size()-2; i>=0; i--){
            ans[i]*=suffix;
            suffix*=nums[i];
        }
        return ans;

        // //dividing product of array by current element
        // vector<int> ans;
        // int pro=1, zero=0;
        // for(int k: nums){
        //     if(k==0) {
        //         zero++;
        //         continue;
        //     }
        //     pro*=k;
        // }
        // for(int i=0; i<nums.size(); i++){
        //     if(zero>1) ans.push_back(0);
        //     else if(zero==1){
        //         if(nums[i]==0) ans.push_back(pro);
        //         else ans.push_back(0);
        //     }else{
        //         ans.push_back(pro/nums[i]);
        //     }
        // }
        // return ans;

        // //brute appraoch
        // vector<int> ans;
        // int pro=1;
        // for(int i=0; i<nums.size(); i++){
        //     pro=1;
        //     for(int j=0; j<nums.size(); j++){
        //         if(i!=j) pro*=nums[j];
        //     }
        //     ans.push_back(pro);
        // }
        // return ans;
    }
};
