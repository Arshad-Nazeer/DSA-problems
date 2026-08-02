class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // deque approach
        vector<int> ans;
        deque<int> dq;
        for(int i=0; i<k; i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        for(int i=k; i<nums.size(); i++){
            while(!dq.empty() & dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;

        // // Priority Queue approach
        // vector<int> ans;
        // priority_queue<pair<int, int>> pq;
        // for(int i=0; i<k; i++){
        //     pq.push({nums[i], i});
        // }
        // ans.push_back(pq.top().first);

        // for(int i=k; i<nums.size(); i++){
        //     while(!pq.empty() && pq.top().second<=i-k){
        //         pq.pop();
        //     }
        //     pq.push({nums[i], i});
        //     ans.push_back(pq.top().first);
        // }
        // return ans;


        // // Brute Force
        // vector<int> ans;
        // int maxwin=INT_MIN;
        // for(int i=0; i<nums.size()-k+1; i++){
        //     int maxwin=INT_MIN;
        //     for(int j=0; j<k; j++){
        //         maxwin=max(maxwin, nums[i+j]);
        //     }
        //     ans.push_back(maxwin);
        // }
        // return ans;
    }
};
