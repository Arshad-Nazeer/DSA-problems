class Solution {
public:
    int minBitFlips(int start, int goal) {
        // accessing each bit of the 32 bits by rightshifitng and performing AND with 1 TC:-O(32) 
        int count=0;
        for(int i=0; i<32; i++){
            if(((start>>i)&1)^((goal>>i)&1)) count++;
        }
        return count;

        // //brian kernighan TC:-O(different bits)
        // start=start^goal; //result contains set bits at indices different in start and goal
        // int count=0;
        // while(start){
        //     start&=(start-1);
        //     count++;
        // }
        // return count;
    }
};