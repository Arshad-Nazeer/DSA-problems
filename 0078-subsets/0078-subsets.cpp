class Solution {
public:
    void recur(vector<vector<int>>& result, vector<int>& nums, int idx, vector<int>& temp){
        if(idx==nums.size()){
            result.push_back(temp);
            return;
        }
        recur(result, nums, idx+1, temp);
        temp.push_back(nums[idx]);
        recur(result, nums, idx+1, temp);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // TC:- O(n*2^n)
        // it will not generate duplicate sets because the numbers in nums are distinct
        vector<vector<int>> result;
        vector<int> temp;
        recur(result, nums, 0, temp);
        return result;
    }
};