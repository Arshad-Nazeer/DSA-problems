class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // //tomfoolery
        // vector<int> rotated(nums.size());
        // for(int i=0; i<nums.size(); i++){
        //     rotated[(i+k)%nums.size()]=nums[i];
        // }
        // nums.assign(rotated.begin(), rotated.end()); 

        // //laand very shit approach incase k is too large
        // if(nums.size()<=1) return;
        // while(k--){
        //     int temp=nums[0];
        //     for(int i=nums.size()-1; i>=0; i--){
        //         nums[(i+1)%nums.size()]=nums[i];
        //     }
        //     nums[1]=temp;
        // }

        k=k%nums.size(); //array repeats after n rotations
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};