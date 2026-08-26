class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0, prev, curr, count=0;
        while(count<=(nums1.size()+nums2.size())/2){
            prev=curr;
            if(i<nums1.size() && j<nums2.size()){
                if(nums1[i]<=nums2[j]) curr=nums1[i++];
                else curr=nums2[j++];
            }else if(i<nums1.size()) curr=nums1[i++];
            else curr=nums2[j++];
            count++;
        }
        if((nums1.size()+nums2.size())%2==0) return (double)(curr+prev)/2;
        else return (double)curr;

        //merge into a third vector approach
        // vector<int> v;
        // int i=0, j=0;
        // while(i<nums1.size() && j<nums2.size()){
        //     if(nums1[i]<=nums2[j]) v.push_back(nums1[i++]);
        //     else v.push_back(nums2[j++]);
        // }
        // while(i<nums1.size()){
        //     v.push_back(nums1[i++]);
        // }
        // while(j<nums2.size()){
        //     v.push_back(nums2[j++]);
        // }
        // if(v.size()%2==0) return (double)(v[v.size()/2]+v[v.size()/2-1])/2;
        // else return (double)v[v.size()/2];
    }
};