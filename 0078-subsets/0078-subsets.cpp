class Solution {
public:
    // void recur(vector<vector<int>>& result, vector<int>& nums, int idx, vector<int>& temp){
    //     if(idx==nums.size()){
    //         result.push_back(temp);
    //         return;
    //     }
    //     recur(result, nums, idx+1, temp);
    //     temp.push_back(nums[idx]);
    //     recur(result, nums, idx+1, temp);
    //     temp.pop_back();
    // }

    // void backtrack(vector<vector<int>>& result, vector<int>& nums, int idx, vector<int>& temp){
    //     result.push_back(temp);
    //     for(int i=idx; i<nums.size(); i++){
    //         temp.push_back(nums[i]);
    //         backtrack(result, nums, i+1, temp);
    //         temp.pop_back();
    //     }
    // }

    vector<vector<int>> subsets(vector<int>& nums) {
        // Recursion TC:- O(n*2^n)
        // it will not generate duplicate sets because the numbers in nums are distinct
        // vector<vector<int>> result;
        // vector<int> temp;
        // recur(result, nums, 0, temp);
        // return result;

        // Backtracking TC:- O(n*2^n)
    
        // this approach is quite similar to recursion just difference in recursion tree made
        // vector<vector<int>> result;
        // vector<int> temp;
        // backtrack(result, nums, 0, temp);
        // return result;

        // bit manipulation (bit masking) TC:- O(n*2^n)
        // There is no recursion stack space
        vector<vector<int>> result;

        for(int mask=0; mask<(1<<nums.size()); mask++){
            vector<int> temp;
            for(int i=0; i<nums.size(); i++){
                if(mask & (1<<i)) temp.push_back(nums[i]);
            }
            result.push_back(temp);
        }
        return result;
    }
};