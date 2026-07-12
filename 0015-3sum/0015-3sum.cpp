class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //optimal approach
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        int j, k;

        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;


            j=i+1, k=nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]<0) j++;
                else if(nums[i]+nums[j]+nums[k]>0) k--;
                else {
                    v.push_back({nums[i], nums[j++], nums[k--]});

                    // while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return v;

        // //Hashing approach
        // sort(nums.begin(), nums.end());
        // set<vector<int>> s;
        // vector<vector<int>> result;
        // for(int i=0; i<nums.size()-2; i++){
        //     set<int> seen;
        //     for(int j=i+1; j<nums.size(); j++){
        //         int complement=-nums[i]-nums[j];
        //         if(seen.find(complement)!=seen.end()){
        //             // vector<int> v={nums[i], nums[j], complement};
        //             // sort(v.begin(), v.end());
        //             s.insert({nums[i], complement, nums[j]});
        //         }
        //         seen.insert(nums[j]);
        //     }
        // }
        // result.assign(s.begin(), s.end());
        // return result;

        // //brute II Aprproach
        // sort(nums.begin(), nums.end());
        // set<vector<int>> s;
        // vector<vector<int>> v;
        // for(int i=0; i<nums.size()-2; i++){
        //     for(int j=i+1; j<nums.size()-1; j++){
        //         auto it = find(nums.begin()+j+1, nums.end(), -(nums[i]+nums[j]));
        //         if(it!=nums.end()){
        //             s.insert({nums[i], nums[j], -(nums[i]+nums[j])});
        //         }
        //     }
        // }
        
        // v.assign(s.begin(), s.end());
        // return v;

        // //brute approach
        // sort(nums.begin(), nums.end());
        // set<vector<int>> s;
        // vector<vector<int>> result;
        // for(int i=0; i<nums.size()-2; i++){
        //     for(int j=i+1; j<nums.size()-1; j++){
        //         for(int k=j+1; k<nums.size(); k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 s.insert({nums[i], nums[j], nums[k]});
        //             }
        //         }
        //     }
        // }

        // result.assign(s.begin(), s.end());
        // return result;
    }
};