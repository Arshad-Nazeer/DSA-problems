class Solution {
public:
    // void backtrack(int k, int target, vector<vector<int>>& ans, vector<int>& temp, int num){
    //     if(temp.size()==k){
    //         if(target==0) ans.push_back(temp);
    //         return;
    //     }
    //     if(num>9) return; 
    //     // This prevents incomplete subsets (size < k) from becoming valid after we've exhausted all available numbers (1–9)
    //     temp.push_back(num);
    //     backtrack(k, target-num, ans, temp, num+1);
    //     temp.pop_back();
    //     backtrack(k, target, ans, temp, num+1);
    // }

    void backtrack(int k, int target, vector<vector<int>>& ans, vector<int>& temp, int num){
        if(temp.size()==k){
            if(target==0) ans.push_back(temp);
            return;
        }
        for(int i=num; i<=9; i++){
            if(i>target) return;  //pruning
            temp.push_back(i);
            backtrack(k, target-i, ans, temp, i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        // //binary backtracking TC:- O(2^9+m*k) : number of valid subsets
        // vector<vector<int>> ans;
        // vector<int> temp;
        // backtrack(k, n, ans, temp, 1);
        // return ans;

        //for loop backtracking
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(k, n, ans, temp, 1);
        return ans;
    }
};