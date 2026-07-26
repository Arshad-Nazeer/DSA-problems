class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        // int xorr=0;
        // for(int &k: nums){
        //     xorr=xorr^k;
        // }
        // return xorr;

        //right and left parts will always be of equal length whether even or odd beacuase total number of eleents is odd
        // if(nums.size()==1) return nums[0];
        
        // int low=0, high=nums.size()-1;
        // while(low<=high){
        //     int mid=(low+high)/2;
        //     if(mid==0 && nums[mid]!=nums[mid+1]) return nums[mid];
        //     if(mid==nums.size()-1 && nums[mid]!=nums[mid-1]) return nums[mid];

        //     if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
        //     else if(mid%2==0){  //L and R parts are even lengths
        //         if(nums[mid==nums[mid-1]]) high=mid-1;
        //         else low=mid+1;
        //     }else if(mid%2!=0){
        //         if(nums[mid]==nums[mid-1]) low=mid+1;
        //         else high=mid-1;
        //     }
        // }
        // return 0;

        int low=0, high=arr.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(mid%2!=0) mid--;
            
            if(arr[mid]==arr[mid+1]) low=mid+2;
            else high=mid;
        }
        return arr[low];
    }
};