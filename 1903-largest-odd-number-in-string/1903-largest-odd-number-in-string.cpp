class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1; i>=0; i--){   //num[i]%2==0 works because ascii value is also in odd for odd numbers
            if(num[i]%2==1) return num.substr(0, i+1);  //stoi(num.substr(i, 1)) //(num[i]-'0')%2!=0 
        }
        return "";
    }
};