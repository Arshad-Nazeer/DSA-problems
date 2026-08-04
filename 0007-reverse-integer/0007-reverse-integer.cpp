class Solution {
public:
    int reverse(int x) {
        //optimal approach
        int ans=0;
        while(x!=0){
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && (x%10)>7)) return 0;   //INT_MAX =  2147483647
            if(ans<INT_MIN/10 || (ans==INT_MIN/10 && (x%10)<-8)) return 0;  //INT_MIN = -2147483648
            ans=ans*10+(x%10);
            x/=10;
        }
        return ans;

        //naive approach
        // long long ans=0;
        // while(x!=0){
        //     ans=ans*10+(x%10);
        //     x=x/10;
        // }
        // if(ans>INT_MAX || ans<INT_MIN) return 0;
        // else return (int)ans;
    }
};