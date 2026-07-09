class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(), nums.end());

        // int zero=0, one=0, two=0;
        // for(auto k: nums){
        //     if(k==0) zero++;
        //     else if(k==2) two++;
        //     else one++;
        // }

        // int i=0;
        // while(zero--) nums[i++]=0;
        // while(one--) nums[i++]=1;
        // while(two--) nums[i++]=2;
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0) {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }else if(nums[mid]==1) mid++;
            else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};