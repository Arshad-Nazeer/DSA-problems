class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> st(nums.begin(), nums.end());
        // nums.assign(st.begin(), st.end());
        // return st.size();

        if(nums.size()<=1) return nums.size();
        int k=1;
        for(int i=1; i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            else nums[k++]=nums[i]; 
        }
        nums.resize(k);
        return nums.size();
    }
};