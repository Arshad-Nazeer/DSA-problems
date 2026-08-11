class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int neg=1, pos=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0) {
                result[neg]=nums[i];
                neg+=2;
            }else{
                result[pos]=nums[i];
                pos+=2;
            }
        }
        return result;

        // int i=0;
        // while(i<nums.size()-1){
        //     int k=i+1;
        //     if(i%2==0 && nums[i]<0){
        //         while(k < nums.size() && nums[k]<0){
        //             k++;
        //         }
        //         swap(nums[i++], nums[k]);
        //     }
        //     else if(i%2!=0 && nums[i]>0){
        //         while(k < nums.size() && nums[k]>0){
        //             k++;
        //         }
        //         swap(nums[i++], nums[k]);
        //     }
        // }
        // return nums;
    }

};