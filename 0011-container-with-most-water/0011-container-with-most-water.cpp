class Solution {
public:
    int maxArea(vector<int>& height) {
        // int area=0;
        // for(int i=0; i<height.size(); i++){
        //     for(int j=i+1; j<height.size(); j++){
        //         area=max(area, (j-i)*min(height[i],height[j]));
        //     }
        // }
        // return area;

        int area=0, left=0, right=height.size()-1;
        while(left<right){
            // if(height[right-1]>=height[right]) right--;
            // else if(height[left+1]>=height[left]) left++;
            // else{
            //     if(height[left+1]>height[right-1]) left++;
            //     else right--;
            // }
            area=max(area, (right-left)*min(height[left], height[right]));
            if(height[left]>height[right]) right--;
            else left++;
            
        }
        return area;
    }
};