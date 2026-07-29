class Solution {
public:
    void splitandmerge(vector<int>& nums, int low, int mid, int high, vector<int>& temp){
        int i=low, j=mid+1, k=low;
        
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        } 
        while(i<=mid){
            temp[k++] = nums[i++];
        }
        while(j<=high){
            temp[k++] = nums[j++];
        }
        for(int i=low; i<=high; i++){
            nums[i]=temp[i];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, vector<int>& temp){
        if(low<high){
            int mid=(low+high)/2;
            mergeSort(nums, low, mid, temp);
            mergeSort(nums, mid+1, high, temp);
            splitandmerge(nums, low, mid, high, temp);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size()-1, temp);
        return nums;
    }
};