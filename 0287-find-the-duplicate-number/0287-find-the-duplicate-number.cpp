class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        //cycle detection-floyd detection
        int slow=arr[0], fast=arr[0];
        slow=0;
        fast=0;
        do{
            slow=arr[slow];
            fast=arr[arr[fast]];
        }while(slow!=fast);
        slow=0;
        while(slow!=fast){
            slow=arr[slow];
            fast=arr[fast];
        }                   
        return slow;

    
        // //sort approach
        // sort(nums.begin(), nums.end());

        // for(int i=1; i<nums.size(); i++){
        //     if(nums[i]==nums[i-1]) return nums[i];
        // }
        // return 0;

        // // hashing approach
        // unordered_map<int, int> mp;
        // for(int k: nums){
        //     mp[k]++;
        //     if(mp[k]==2) return k;
        // }
        // return 0;

        // //set approach
        // unordered_set<int> s;
        // for(int k: nums){
        //     if(s.find(k)!=s.end()) return k;
        //     s.insert(k);
        // }
        // return 0;
    }
};