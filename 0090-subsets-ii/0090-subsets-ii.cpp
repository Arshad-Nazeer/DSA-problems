class Solution {
public:
    // void backtrack(vector<vector<int>>& result, vector<int>& nums, int idx, vector<int>& temp){
    //     result.push_back(temp);
    //     for(int i=idx; i<nums.size(); i++){
    //         if(i!=idx && nums[i]==nums[i-1]) continue;
    //         temp.push_back(nums[i]);
    //         backtrack(result, nums, i+1, temp);
    //         temp.pop_back();
    //     }
    // }

    void recur(vector<vector<int>>& result, vector<int>& nums, int idx, vector<int>& temp){
        if(idx==nums.size()) {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        recur(result, nums, idx+1, temp);
        temp.pop_back();
        // check for repeating element before going for exclude
        while(idx+1<nums.size()&& nums[idx]==nums[idx+1]) idx++;
        recur(result, nums, idx+1, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // //backtrack TC:-O(n*k)=no. of unqiue subsets, worst case:- O(n*2^n)
        // sort(nums.begin(), nums.end());
        // vector<vector<int>> result;
        // vector<int> temp;
        // backtrack(result, nums, 0, temp);
        // return result;

        //recursion
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        recur(result, nums, 0, temp);
        return result;
    }
};