class Solution {
public:
    void getperm(vector<int>& nums, int index, vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            getperm(nums, index+1, ans);
            swap(nums[index], nums[i]); 
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getperm(nums, 0, ans);
        return ans;
    }
};