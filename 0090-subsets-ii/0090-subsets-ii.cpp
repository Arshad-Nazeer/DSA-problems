class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& nums, int idx, vector<int>& temp){
        result.push_back(temp);
        for(int i=idx; i<nums.size(); i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            backtrack(result, nums, i+1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(result, nums, 0, temp);
        return result;
    }
};