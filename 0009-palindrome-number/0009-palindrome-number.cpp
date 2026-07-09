  class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        long int temp=x, pal=0;
        while(temp!=0){
            pal=pal*10+(temp%10);
            temp=temp/10;
        }
        if(pal==x) return 1;
        else return 0;
    }
};