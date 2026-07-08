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

    // void recur(vector<vector<int>>& result, vector<int>& nums, int idx, vector<int>& temp){
    //     if(idx==nums.size()) {
    //         result.push_back(temp);
    //         return;
    //     }
    //     temp.push_back(nums[idx]);
    //     recur(result, nums, idx+1, temp);
    //     temp.pop_back();
    //     // check for repeating element before going for exclude
    //     while(idx+1<nums.size() && nums[idx]==nums[idx+1]) idx++;
    //     recur(result, nums, idx+1, temp);
    // }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // //backtrack TC:-O(n*k)=no. of unqiue subsets, worst case:- O(n*2^n)
        // sort(nums.begin(), nums.end());
        // vector<vector<int>> result;
        // vector<int> temp;
        // backtrack(result, nums, 0, temp);
        // return result;

        // //recursion TC:-O(n*k)=no. of unqiue subsets, worst case:- O(n*2^n)
        // sort(nums.begin(), nums.end());
        // vector<vector<int>> result;
        // vector<int> temp;
        // recur(result, nums, 0, temp);
        // return result;

        //bitmask (bit manipulation)
        // Reject any mask that selects a duplicate element without selecting its previous occurrence.
        // A duplicate can be selected only if its previous duplicate is also selected.
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int mask=0; mask<(1<<nums.size()); mask++){
            vector<int> temp;
            bool valid=true;
            for(int i=0; i<nums.size(); i++){
                if(mask & (1<<i)){
                    if(i>0 && nums[i]==nums[i-1] && !(mask&(1<<(i-1)))){
                        valid=false;
                        break;
                    }
                    temp.push_back(nums[i]);
                }
            }
            if(valid) result.push_back(temp);
        }
        return result;
    }
};