class Solution {
public:
    // void getperm(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, vector<bool>& used){  //lexicographically TC:-O(n!*n), C:-O(n)
    //     if(temp.size()==nums.size()){
    //         ans.push_back(temp);
    //         return;
    //     }

    //     for(int i=0; i<nums.size(); i++){
    //         if(used[i]) continue;
    //         used[i]=true;
    //         temp.push_back(nums[i]);
    //         getperm(nums, ans, temp, used);
    //         temp.pop_back();
    //         used[i]=false;
    //     }
    // }

    // void getperm(vector<int>& nums, int index, vector<vector<int>>& ans){
    //     if(index==nums.size()){ //TC:-O(n!*n), SC:- O(n!*n), stack space:-O*(n)
    //         ans.push_back(nums);
    //         return;
    //     }
    //     for(int i=index; i<nums.size(); i++){
    //         swap(nums[index], nums[i]);
    //         getperm(nums, index+1, ans);
    //         swap(nums[index], nums[i]); 
    //     }
    // }

    vector<vector<int>> permute(vector<int>& nums) { 
        //STL function TC:-O(n × n!), SC:-O(1) [no recursion]
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans;
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end())); //fuction TC:-O(n)
        return ans;

        //lexicographically
        // sort(nums.begin(), nums.end()); 
        // vector<vector<int>> ans;
        // vector<bool> used(nums.size(), false);
        // vector<int> temp;
        // getperm(nums, ans, temp, used);
        // return ans;

        //swap-baseed(can mess up order)
        // vector<vector<int>> ans;
        // getperm(nums, 0, ans);
        // // sort(ans.begin(), ans.end());
        // return ans;
    }
};