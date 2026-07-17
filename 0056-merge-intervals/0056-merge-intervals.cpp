class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // for (int i = 0; i < intervals.size() - 1; i++) {
        //     for (int j = 0; j < intervals.size() - i - 1; j++) {
        //         if (intervals[j][0] > intervals[j + 1][0] || (intervals[j][0] == intervals[j+1][0] && intervals[j][1] > intervals[j+1][1])) {
        //             swap(intervals[j], intervals[j + 1]);
        //         }
        //     }
        // }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++){
            vector<int>& last=result.back();
            if(last[1]>=intervals[i][0]) last[1]=max(last[1], intervals[i][1]);
            else result.push_back(intervals[i]);
        }

        return result;
  
        // vector<int> remove;
        // for(int i=0; i<intervals.size()-1; i++){
        //     if(intervals[i][1]<intervals[i+1][0]) continue;
        //     else if(intervals[i][1]>=intervals[i+1][0] && intervals[i][1]<intervals[i+1][1]){
        //         intervals[i+1][0]=intervals[i][0];
        //     }else if(intervals[i][1]>=intervals[i+1][1]){
        //         intervals[i+1][0]=intervals[i][0];
        //         intervals[i+1][1]=intervals[i][1];
        //     }
        //     remove.push_back(i);
        // }

        // for(int k: remove){
        //     intervals.erase(intervals.begin()+k);
        // }
        // return intervals;
    }
};