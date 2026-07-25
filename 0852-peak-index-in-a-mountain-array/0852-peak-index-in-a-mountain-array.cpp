class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // for(int i=0; i<arr.size(); i++){
        //     if(arr[i]>arr[i+1]) return i;
        // }
        // return 0;

        // int low=1, high=arr.size()-2; //to handle out of bounds
        // while(low<=high){
        //     int mid=low+(high-low)/2;
        //     if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid;
        //     else if(arr[mid]<arr[mid+1]) low=mid+1;
        //     else high=mid-1;
        // }
        // return 0;

        int low=0, high=arr.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(arr[mid]<arr[mid+1]) low=mid+1;
            else high=mid;
        }
        return low;
    }
};