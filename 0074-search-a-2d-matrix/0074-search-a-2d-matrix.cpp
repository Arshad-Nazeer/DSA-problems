class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // for(auto k: matrix){
        //     if(count(k.begin(), k.end(), target)) return 1;
        // }
        // return 0;

        // int low=0, high=matrix.size()-1, mid;
        // while(low<=high){
        //     mid=(high+low)/2;
        //     if(target<matrix[mid][0]) high=mid-1;
        //     else if(target>matrix[mid][(matrix[0]).size()-1]) low=mid+1;
        //     else{
        //         low=0, high=(matrix[mid]).size()-1;
        //         while(low<=high){
        //             int middle=(high+low)/2;
        //             if(target<matrix[mid][middle]) high=middle-1;
        //             else if(target>matrix[mid][middle]) low=middle+1;
        //             else return 1;
        //         }
        //     }
        // }
        // return 0;

        int low=0, high=(matrix[0].size())*(matrix.size())-1, cols=matrix[0].size(), mid;

        while(low<=high){
            mid=(low+high)/2;
            if(target<matrix[mid/cols][mid%cols]) high=mid-1;
            else if(target>matrix[mid/cols][mid%cols]) low=mid+1;
            else return 1;
        }
        return 0;
    }
};